package Concurrency.Chapter03_Inter_Thread_Communication.Example1;

public class No_Synchronization {
    
    public static int counter = 0;

    public static void process() {

        Thread t1 = new Thread(new Runnable(){

            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    // This operation is not a single atomic operation
                    // It includes reading the int from memory, writing the number to memory
                    counter++;
                }
            }
            
        });

        Thread t2 = new Thread(new Runnable(){

            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    // This operation is not a single atomic operation
                    // It includes reading the int from memory, writing the number to memory
                    counter++;
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

        // 结果少数情况下，counter可能不是200
        // 原因是 counter++ 并不是“元操作”
        process();

    }

}
