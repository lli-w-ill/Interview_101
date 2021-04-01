package Concurrency.Chapter01_Multithreading.Example2;

class Worker implements Runnable {

    // `volatile` guarantees that the CPU is not going to cache this variable and forces the variable is stored in the main memory (RAM)
    private volatile boolean terminated;

    @Override
    public void run() {

        while(!terminated) {
            System.out.println("Working class is running...");
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    public boolean isTerminated() {
        return terminated;
    }

    public void setTerminated(boolean terminated) {
        this.terminated = terminated;
    }

}

public class Example2 {
    
    public static void main(String[] args) {

        Worker worker = new Worker();
        Thread t1 = new Thread(worker);

        t1.start();

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        worker.setTerminated(true);
        System.out.println("Algorithm is terminated...");
    }

}
