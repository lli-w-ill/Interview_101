package Concurrency.Chapter01_Multithreading.Example2;

class Runner111 extends Thread {

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

class Runner222 extends Thread {

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


public class Example2_extends_Thread {
    
    public static void main(String[] args) {

        Thread t1 = new Runner111();
        Thread t2 = new Runner222();

        t1.start();
        t2.start();

    }

}
