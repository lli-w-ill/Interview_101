package Concurrency.Chapter04_Threads_with_Executors.Example2;

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
            Thread.currentThread().interrupt();
        }

    }
    
}
public class Example2 {
 
    public static void main(String[] args) {

        // create a thread pool with 5 threads
        ExecutorService executor = Executors.newFixedThreadPool(5);

        for (int i = 0; i < 100; i++) {
            // 每个thread执行一个任务
            executor.execute(new Task(i));
        }

        // the program will not be terminated
        // because we have to shut down the executor!!!
        // we prevent the executor to execute any further tasks
        executor.shutdown();

        // terminate actual (running) tasks
        try {
            if (!executor.awaitTermination(1000, TimeUnit.MILLISECONDS)) {
                // wait for 1000 millisecond
                // if the return value is false, then terminate all active running tasks 

                // 注释掉这一行的话，只有完成100个任务之后才会结束 executor
                // 如果不注释这一行的话，如果等待时间超过1000毫秒，则终止所有任务
                executor.shutdownNow();
            }
        } catch (InterruptedException e) {
            executor.shutdownNow();
        }
    }

}
