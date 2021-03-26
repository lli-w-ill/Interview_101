package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example1;

// Component 4: Client -- decides which commands to execute at which point. To execute a command, it passes the command object to the invoker object.
public class Example1 {
    
    public static void main(String[] args) {
        
        Switcher switcher = new Switcher();

        Light light = new Light();
        TurnOnCommand onCommand = new TurnOnCommand(light);
        TurnOffCommand offCommand = new TurnOffCommand(light);

        switcher.addCommand(onCommand);
        switcher.addCommand(offCommand);

        switcher.executeCommands();

    }

}
