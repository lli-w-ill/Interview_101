package Concurrency.Chapter01_Multithreading.Example5;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;

/**
 * semaphore maintains a set of permits
 *  - acquire(): if a permit is available then takes it
 *  - release(): adds a permit
 */

enum Downloader {
    // thread-safe
    INSTANCE;

    // 只允许3个线程访问资源
    private Semaphore semaphore = new Semaphore(3, true);

    public void downloadData() {
        try {
            // get a lock
            semaphore.acquire();

            download();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            // release the lock
            semaphore.release();
        }

    }

    private void download() {
        System.out.println("Downloading data from the web...");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Example5 {
    
    public static void main(String[] args) {

        ExecutorService executorService = Executors.newCachedThreadPool();

        for (int i = 0; i < 12; i++) {
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    Downloader.INSTANCE.downloadData();
                }
            });
        }
    }

}

