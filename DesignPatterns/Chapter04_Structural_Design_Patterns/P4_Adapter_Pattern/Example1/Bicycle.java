package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example1;

// Bicycle is not a vehicle that can accelerate
// We need to create an Adapter layer that make Bicycle compatible with Bus and Car which can accelerate
public class Bicycle {

    public void go() {
        System.out.println("Using bicycle...");
    }
    
}
