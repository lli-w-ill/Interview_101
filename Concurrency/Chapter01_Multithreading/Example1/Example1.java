package Concurrency.Chapter01_Multithreading.Example1;

public class Example1 {
    
    private static int counter = 0;

    public static synchronized void increment(int threadNo) {
        counter++;
        System.out.println("thread#" + threadNo + " " + counter);
    }

    public static void process() {

        Thread t1 = new Thread(new Runnable() {

            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    increment(1);
                }
            }

        });

        Thread t2 = new Thread(new Runnable(){
            
            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    increment(2);
                }
            }

        });

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        process();
    }
}
