package Concurrency.Chapter02_Threads_Manipulation.Example3;

class DaemonWorker implements Runnable {

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Daemon Thread is running...");
        }
    }

}

class NormalWorker implements Runnable {

    @Override
    public void run() {
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Normal Thread finishes execution...");
    }

}


public class Daemon_Worker {
    
    public static void main(String[] args) {

        Thread t1 = new Thread(new DaemonWorker());
        Thread t2 = new Thread(new NormalWorker());
        t1.setDaemon(true);

        // t1 is going to be terminated by JVM when all other normal worker threads finish the execution
        t1.start();
        t2.start();

        System.out.println("All threads finish...");

    }

}
