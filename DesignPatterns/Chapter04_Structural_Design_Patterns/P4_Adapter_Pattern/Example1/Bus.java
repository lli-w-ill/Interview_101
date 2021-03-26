package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example1;

public class Bus implements Vehicle {
    
    @Override
    public void accelerate() {
        System.out.println("Bus is accelerating...");
    }

}
