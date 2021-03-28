package Concurrency.Chapter01_Multithreading.Example2;

public class Example2_anonymous_Runnable {
    
    public static void main(String[] args) {

        Thread t1 = new Thread(new Runnable() {

            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    System.out.println("Runner1: " + i);
                }
            }

        });

        Thread t2 = new Thread(new Runnable() {

            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    System.out.println("Runner2: " + i);
                }
            }

        });

        t1.start();
        t2.start();

    }

}
