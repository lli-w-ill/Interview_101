package Concurrency.Chapter03_Inter_Thread_Communication.Example1;

public class Synchronization {
    
    public static int counter = 0;

    // we have to make sure this method is executed only by a single thread at a given time
    // USE synchronized KEYWORD
    public static synchronized void increment() {
        // This operation is not a single atomic operation
        // It includes reading the int from memory, writing the number to memory
        counter++;
    }

    public static void process() {

        Thread t1 = new Thread(new Runnable(){

            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    increment();
                }
            }
            
        });

        Thread t2 = new Thread(new Runnable(){

            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    increment();
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
        
        System.out.println("The counter is: " + counter);

    }

    public static void main(String[] args) {
        
        process();

    }

}
