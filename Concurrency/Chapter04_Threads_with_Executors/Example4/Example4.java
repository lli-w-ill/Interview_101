package Concurrency.Chapter04_Threads_with_Executors.Example4;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

class Processor implements Callable<String> {

    private int id;

    public Processor(int id) {
        this.id = id;
    }

    @Override
    public String call() throws Exception {
        Thread.sleep(1000);
        
        return "Id: " + id;
    }

}

public class Example4 {
    
    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(2);

        List<Future<String>> list = new ArrayList<>();

        for (int i = 0; i < 5; i++) {
            // use submit() instead of execute()
            Future<String> future = executorService.submit(new Processor(i + 1));

            // get the return value returned by the thread
            list.add(future);
        }

        // print all returned values
        for (Future<String> future : list) {
            try {
                System.out.println(future.get());
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        }

        // stop the executor service
        executorService.shutdown();

    }

}
