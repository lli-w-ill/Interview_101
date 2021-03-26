package DesignPatterns.Chapter04_Structural_Design_Patterns.P1_Decorator_Pattern.Example1;

public class PlainBeverage implements Beverage {

    @Override
    public int getCost() {
        // plain beverage: $5
        return 5;
    }

    @Override
    public String getDescription() {
        return "Plain beverage + ";
    }
    
}
