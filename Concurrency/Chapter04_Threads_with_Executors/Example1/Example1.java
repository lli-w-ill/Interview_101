package Concurrency.Chapter04_Threads_with_Executors.Example1;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

class Task implements Runnable {

    private int id;

    public Task(int id) {
        this.id = id;
    }

    @Override
    public void run() {
        
        System.out.println("Task with id " + id + " is in work - thread name: " + Thread.currentThread().getName());

        // generate a random duration
        long duration = (long) (Math.random() * 5);

        try {
            TimeUnit.SECONDS.sleep(duration);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
    
}
public class Example1 {
 
    public static void main(String[] args) {

        // it is a single thread that will execute the tasks sequentially 
        // so one after another
        ExecutorService executor = Executors.newSingleThreadExecutor();

        for (int i = 0; i < 10; i++) {
            executor.execute(new Task(i));
        }

        // the program will not be terminated
        // because we have to shut down the executor!!!
        // executor service will not execute further tasks
        executor.shutdown();

    }

}
