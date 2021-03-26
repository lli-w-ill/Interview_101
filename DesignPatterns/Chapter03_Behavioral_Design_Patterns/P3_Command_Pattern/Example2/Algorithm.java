package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example2;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

// Component 3: Invoker
public class Algorithm {
    
    // use BlockingQueue to make sure that if multiple threads manipulate the same queue, there is not gonna be inconsistences (synchronized)
    private BlockingQueue<Command> commandList;

    public Algorithm() {
        // capacity = 10
        this.commandList = new ArrayBlockingQueue<>(10);
    }

    // produce a task
    public void produce() {

        try {
            for (int i = 0; i < 10; i++) {
                commandList.put(new TaskSolver(new Task(i + 1)));
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    // consume a task
    public void consume() {

        try {
            for (int i = 0; i < 10; i++) {
                Thread.sleep(1000);

                // execute generated tasks one by one
                commandList.take().execute();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}
