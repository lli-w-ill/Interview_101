package Concurrency.Chapter02_Threads_Manipulation.Example1;

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
