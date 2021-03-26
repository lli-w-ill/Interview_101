package DesignPatterns.Chapter04_Structural_Design_Patterns.P1_Decorator_Pattern.Example1;

public class Milk extends BeverageDecorator {
    
    private Beverage beverage;

    public Milk(Beverage beverage) {
        super(beverage);

        this.beverage = beverage;
    }

    @Override
    public int getCost() {
        // milk: $3
        return this.beverage.getCost() + 3;
    }

    @Override
    public String getDescription() {
        return this.beverage.getDescription() + "milk + ";
    }
    
}
