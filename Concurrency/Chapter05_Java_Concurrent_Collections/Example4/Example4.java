package Concurrency.Chapter05_Java_Concurrent_Collections.Example4;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.DelayQueue;
import java.util.concurrent.Delayed;
import java.util.concurrent.TimeUnit;

/**
 * This is an unbounded BlockingQueue of objects that implement the Delayed
 * interface
 * 
 * - DelayQueue keeps the elements internally until a certain delay has expired
 * 
 * - an object can only be taken from the queue when its delay has expired !!! -
 * 
 * We cannot place null items in the queue - The queue is sorted so that the
 * object at the head has a delay that has expired for the longest time.
 * 
 * If no delay has expired, then there is no head element and poll( ) will
 * return null
 * 
 * size() return the count of both expired and unexpired items !!!
 *
 */

class DelayedWorker implements Delayed {

    private long duration;
    private String message;

    public DelayedWorker(long duration, String message) {
        this.duration = System.currentTimeMillis() + duration;
        this.message = message;
    }

    @Override
    public int compareTo(Delayed o) {
        // tell how to sort the delayed items
        if (this.duration < ((DelayedWorker) o).getDuration()) {
            // this 小于 o
            return -1;
        } else if (this.duration > ((DelayedWorker) o).getDuration()) {
            // this 大于 o
            return 1;
        } 
        return 0;
    }

    @Override
    public long getDelay(TimeUnit unit) {
        // tell how much time we have to wait if we want to take out the items from the queue
        return unit.convert(duration - System.currentTimeMillis(), TimeUnit.MILLISECONDS);
    }

    public long getDuration() {
        return duration;
    }

    public void setDuration(long duration) {
        this.duration = duration;
    }

    @Override
    public String toString() {
        return this.message;
    }
}

public class Example4 {
    
    public static void main(String[] args) {

        BlockingQueue<DelayedWorker> queue = new DelayQueue<>();

        try {
            queue.put(new DelayedWorker(10000, "This is the first message..."));
            queue.put(new DelayedWorker(1000, "This is the second message..."));
            queue.put(new DelayedWorker(4000, "This is the third message..."));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        while (!queue.isEmpty()) {
            try {
                // 首先那 second，因为second的delay最小，也就是expire时间最长
                // 其次拿 third，最后拿first
                System.out.println(queue.take());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

}
