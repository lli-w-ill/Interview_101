package Concurrency.Chapter02_Threads_Manipulation.Example2;

class Runner1 extends Thread {

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Runner1: " + i);
        }
    }

}

class Runner2 extends Thread {

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            try {
                // sleep for 100 milliseconds
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Runner2: " + i);
        }
    }

}


public class Example3 {
    
    public static void main(String[] args) {

        Thread t1 = new Runner1();
        Thread t2 = new Runner2();

        t1.start();
        t2.start();

        // wait for threads to finish, and then print "Finished with threads..."
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Finished with threads...");

    }

}
