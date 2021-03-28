package Concurrency.Chapter02_Threads_Manipulation.Example3;

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