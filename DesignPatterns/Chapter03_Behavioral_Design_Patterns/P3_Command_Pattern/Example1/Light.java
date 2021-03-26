package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P3_Command_Pattern.Example1;

// Component 2: Receiver -- does the work itself
public class Light {
    
    public void turnOn() {
        System.out.println("Lights are on...");
    }

    public void turnOff() {
        System.out.println("Lights are off...");
    }

}
