package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example1;

// Component 1: Command concrete class 
public class TurnOnCommand implements Command {
    
    private Light light;

    public TurnOnCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        this.light.turnOn();
    }
}
