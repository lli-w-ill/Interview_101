package Concurrency.Chapter01_Multithreading.Example3;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Example3_livelock {
    
    private Lock lock1 = new ReentrantLock(true);
    private Lock lock2 = new ReentrantLock(true);

    public void worker1() {

        while (true) {
            try {
                Thread.sleep(500);
            } catch (InterruptedException e1) {
                e1.printStackTrace();
            }

            // try to get the lock1 for 50 milliseconds
            try {
                lock1.tryLock(50, TimeUnit.MILLISECONDS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Worker1 acquires the lock1...");
            System.out.println("Worker1 tries to get lock2...");


            if (lock2.tryLock()) {
                System.out.println("Worker1 acquires the lock2...");
                lock2.lock();
            } else {
                System.out.println("Worker1 cannot acquire lock2...");
                continue;
            }
        
            break;
        }

        lock1.unlock();
        lock2.unlock();
    }

    public void worker2() {
        while (true) {
            try {
                Thread.sleep(500);
            } catch (InterruptedException e1) {
                e1.printStackTrace();
            }

            // try to get the lock2 for 50 milliseconds
            try {
                lock2.tryLock(50, TimeUnit.MILLISECONDS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Worker2 acquires the lock2...");
            System.out.println("Worker2 tries to get lock1...");


            if (lock1.tryLock()) {
                System.out.println("Worker2 acquires the lock1...");
                lock1.lock();
            } else {
                System.out.println("Worker2 cannot acquire lock1...");
                continue;
            }
        
            break;
        }

        lock1.unlock();
        lock2.unlock();
    }

    public static void main(String[] args) {

        Example3_livelock livelock = new Example3_livelock();

        // after Java 8 it is possible to creates threads like this
        new Thread(livelock::worker1, "worker1").start();

        new Thread(livelock::worker2, "worker2").start();

    }

}
