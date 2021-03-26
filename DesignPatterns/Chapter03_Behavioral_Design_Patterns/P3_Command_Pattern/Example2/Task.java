package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example2;

// Component 2: Receiver
public class Task {
 
    private int id;

    public Task(int id) {
        this.id = id;
    }

    public void solveProblem() {
        System.out.println("Solving the problem with ID " + this.id);
    }

}
