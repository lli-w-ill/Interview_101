package Concurrency.Chapter03_Inter_Thread_Communication.Example4;

import java.util.ArrayList;
import java.util.List;

class Processor {

    private List<Integer> list = new ArrayList<>();
    private static final int UPPER_LIMIT = 5;
    private static final int LOWER_LIMIT = 0;
    private final Object lock = new Object();
    private int value = 0;

    public void producer() throws InterruptedException {

        // insert 0, 1, 2, 3, 4 to list
        synchronized(lock) {
            while (true) {
                if (list.size() == UPPER_LIMIT) {
                    System.out.println("Producer: Waiting for removing items...");
                    // release the lock until the other thread calls notify()
                    lock.wait();
                } else {
                    System.out.println("Producer: Adding " + value);
                    list.add(value);
                    value++;
                    // we can call notify() - because the other thread will be notified only when it is in a waiting state
                    lock.notify();
                }
                Thread.sleep(500);
            }
        }

    }

    public void consumer() throws InterruptedException {

        // remove 4, 3, 2, 1, 0
        synchronized(lock) {
            while (true) {
                if (list.size() == LOWER_LIMIT) {
                    System.out.println("Consumer: Waiting for adding items...");
                    lock.wait();
                } else {
                    System.out.println("Consumer: Removing: " + list.remove(list.size() - 1));
                    value--;
                    // notify wakes up producer
                    lock.notify();
                }
                Thread.sleep(500);
            }
        }
        
    }

}

public class Example4 {
    
    public static void main(String[] args) {

        Processor process = new Processor();

        Thread t1 = new Thread(new Runnable(){
            @Override
            public void run() {
                try {
                    process.producer();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread t2 = new Thread(new Runnable(){
           @Override
           public void run() {
               try {
                   process.consumer();
               } catch (InterruptedException e) {
                   e.printStackTrace();
               }
           } 
        });

        t1.start();
        t2.start();

    }

}
