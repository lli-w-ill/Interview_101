package Concurrency.Chapter05_Java_Concurrent_Collections.Example3;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

/**
 * 
 * 	BlockingQueue -> an interface that represents a queue that is thread safe
 * 		Put items or take items from it ...
 * 
 * 		For example: one thread putting items into the queue and another thread taking items from it
 * 			at the same time !!!
 * 				We can do it with producer-consumer pattern !!!
 * 
 * 		put() putting items to the queue
 * 		take() taking items from the queue
 * 
 */

class FirstWorker implements Runnable {

    private BlockingQueue<Integer> blockingQueue;

    public FirstWorker(BlockingQueue<Integer> blockingQueue) {
        this.blockingQueue = blockingQueue;
    }

    @Override
    public void run() {
        int counter = 0;
        while (true) {
            try {
                System.out.println("Putting item (counter = " + counter + ") to the queue");
                blockingQueue.put(counter++);
                Thread.sleep(100);  // 插入速度大于take速度，thread is going to wait
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
}

class SecondWorker implements Runnable {

    private BlockingQueue<Integer> blockingQueue;

    public SecondWorker(BlockingQueue<Integer> blockingQueue) {
        this.blockingQueue = blockingQueue;
    }

    @Override
    public void run() {
        while (true) {
            try {
                int number = blockingQueue.take();
                System.out.println("Taking item (counter = " + number + ") from the queue");
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
}


public class Example3 {
    
    public static void main(String[] args) {

        BlockingQueue<Integer> queue = new ArrayBlockingQueue<>(10);

        FirstWorker firstWorker = new FirstWorker(queue);
        SecondWorker secondWorker = new SecondWorker(queue);
        
        new Thread(firstWorker).start();
        new Thread(secondWorker).start();

    }

}
