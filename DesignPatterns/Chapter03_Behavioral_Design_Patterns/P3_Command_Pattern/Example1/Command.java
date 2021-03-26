package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example1;

// Component 1: Command interface -- knows about receiver and invokes a method of the receiver. Values for parameters of the receiver method are stored in the command
public interface Command {

    public void execute();
    
}
