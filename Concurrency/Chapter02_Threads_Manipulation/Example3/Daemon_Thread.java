package Concurrency.Chapter02_Threads_Manipulation.Example3;

public class Daemon_Thread {
    
    public static void main(String[] args) {

        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Daemon Thread...");
            }
        });

        t1.setDaemon(true);

        System.out.println(t1.isDaemon());
    }

}
