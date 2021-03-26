package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example2;

/**
 * Commands package a piece of computation.
 * 
 * This computation may be invoked long after the command objects are created.
 * 
 * These commands can be invoked by different threads
 * 
 * Topics:  schedulers, thread pools, job queues ...
 */
// Commponent 4: Client
public class Example2 {
    
    public static void main(String[] args) {

        final Algorithm algorithm = new Algorithm();

        // in the first thread, we create tasks
        Thread t1 = new Thread(new Runnable(){
            @Override
            public void run() {
                algorithm.produce();
            }
        });

        // in the second thread, we execute tasks
        Thread t2 = new Thread(new Runnable(){
            @Override
            public void run() {
                algorithm.consume();
            }
        });

        t1.start();
        t2.start();

    }

}
