package Concurrency.Chapter03_Inter_Thread_Communication.Example3;

class Process {

    public void produce() throws InterruptedException {

        synchronized(this) {
            System.out.println("Running the produce method...");
            
            // release the intrinsic lock
            wait();

            System.out.println("Again in the producer method...");
        }

    }

    public void consume() throws InterruptedException {

        Thread.sleep(1000);
        synchronized(this) {
            System.out.println("Consume method is executed...");

            // notify waiting thread to continue its execution
            // 这个线程不会『马上』notify其他waiting threads，而是需要等到该线程结束后再notify
            notify();

            // after notify() method
            for (int i = 5; i > 0; i--) {
                Thread.sleep(1000);
                System.out.println(i);
            }

            // IMPORTANT: notify other waiting threads
        }

    }

}

public class Example3 {
    
    public static void main(String[] args) {

        Process process = new Process();

        Thread t1 = new Thread(new Runnable(){
            @Override
            public void run() {
                try {
                    process.produce();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread t2 = new Thread(new Runnable(){
            @Override
            public void run() {
                try {
                    process.consume();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        t1.start();
        t2.start();
    }

}
