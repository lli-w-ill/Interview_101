package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example2;

// Component 1: Command concrete class
public class TaskSolver implements Command {
    
    private Task task;

    public TaskSolver(Task task) {
        this.task = task;
    }

    @Override
    public void execute() {
        this.task.solveProblem();
    }
}
