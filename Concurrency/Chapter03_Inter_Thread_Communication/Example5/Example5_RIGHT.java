package Concurrency.Chapter03_Inter_Thread_Communication.Example5;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Reentrant Lock
 *      - it has the same behavior as the "synchronized" approach
 *      - it has some additional features
 *          * new ReentrantLock(boolean fairness)
 *              fairness is set to be true --> the longest-waiting thread will get the lock
 *              fairness is set to be false --> there is no access order
 * 
 *      IMPORTANT: we have to use try-catch block when doing critical section that may throw exceptions, and call unlock() in the final block.
 * 
 */
public class Example5_RIGHT {
   
    private static int counter = 0;
    private static Lock lock = new ReentrantLock();

    public static void increment() {

        /*
        lock.lock();

        // 问题：如果for loop中抛出异常，那么unlock则不会执行，所以这里需要try-catch
        for (int i = 0; i < 10000; i++) {
            counter++;
        }

        lock.unlock();
        */

        lock.lock();
        
        try {
            for (int i = 0; i < 10000; i++) {
                counter++;
            }
        } finally {
            lock.unlock();
        }

    }

    public static void main(String[] args) {

        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                increment();
            }
        });

        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                increment();
            }
        });

        t1.start();
        t2.start();
    
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // 正确的 counter 应该是 20000
        System.out.println("Counter is: " + counter);
        

    }

}
