package Concurrency.Chapter01_Multithreading.Example4;

class Worker implements Runnable {

    @Override
    public void run() {
        System.out.println("Worker Thread...");
    }

}

public class Worker_Thread {
 
    public static void main(String[] args) {

        Thread t1 = new Thread(new Worker());
        t1.start();
        
    }

}