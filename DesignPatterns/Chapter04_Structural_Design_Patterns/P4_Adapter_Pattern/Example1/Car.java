package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example1;

public class Car implements Vehicle {

    @Override
    public void accelerate() {
        System.out.println("Car is accelerating...");
    }
    
}
