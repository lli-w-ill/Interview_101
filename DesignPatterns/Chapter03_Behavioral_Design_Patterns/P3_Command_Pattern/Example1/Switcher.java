package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example1;

import java.util.ArrayList;
import java.util.List;

// Component 3: Invoker -- knows how to execute a command, and optionally does bookkeeping about the command execution. Invoker does not know anything about a concrete command, it knows only about command interface!
public class Switcher {
    
    public List<Command> commands;

    public Switcher() {
        this.commands = new ArrayList<>();
    }

    public void addCommand(Command command) {
        this.commands.add(command);
    }

    public void executeCommands() {
        for (Command command : commands) {
            command.execute();
        }
    }
}
