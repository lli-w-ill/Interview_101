package Concurrency.Chapter05_Java_Concurrent_Collections.Example5;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.PriorityBlockingQueue;

/**
 * It implements the BlockingQueue interface
 * 
 * 	- unbounded concurrent queue
 * 	- it uses the same ordering rules as the java.util.PriorityQueue class -> have to implement the COmparable interface
 * 			The comparable interface will determine what will the order in the queue
 * 
 * 			The priority can be the same compare() == 0 case
 * 
 *  - no null items !!!
 * 
 *
 */

class FirstWorker implements Runnable {

    private BlockingQueue<Person> blockingQueue;

    public FirstWorker(BlockingQueue<Person> blockingQueue) {
        this.blockingQueue = blockingQueue;
    }

    @Override
    public void run() {
        try {
            blockingQueue.put(new Person(10, "Ali"));
            blockingQueue.put(new Person(65, "Zash"));
            blockingQueue.put(new Person(30, "Mary"));
            Thread.sleep(1000);
            blockingQueue.put(new Person(25, "Hill"));
            Thread.sleep(1000);
            blockingQueue.put(new Person(45, "Peter"));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}

class SecondWorker implements Runnable {

    private BlockingQueue<Person> blockingQueue;

    public SecondWorker(BlockingQueue<Person> blockingQueue) {
        this.blockingQueue = blockingQueue;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(3000);
            System.out.println(blockingQueue.take());
            Thread.sleep(1000);
            System.out.println(blockingQueue.take());
            Thread.sleep(1000);
            System.out.println(blockingQueue.take());
            System.out.println(blockingQueue.take());
            System.out.println(blockingQueue.take());
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}

class Person implements Comparable<Person> {

    private int age;
    private String name;

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    @Override
    public int compareTo(Person o) {
        if (this.age > o.age) {
            return 1;
        } else if (this.age < o.age) {
            return -1;
        }
        return 0;
    }

    @Override
    public String toString() {
        return this.age + " " + this.name;
    }

}

public class Example5 {
    
    public static void main(String[] args) {

        BlockingQueue<Person> queue = new PriorityBlockingQueue<>();

        new Thread(new FirstWorker(queue)).start();
        new Thread(new SecondWorker(queue)).start();

    }

}
