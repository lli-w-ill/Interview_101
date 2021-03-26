package DesignPatterns.Chapter04_Structural_Design_Patterns.P1_Decorator_Pattern.Example1;

public class Sugar extends BeverageDecorator {

    private Beverage beverage;

    public Sugar(Beverage beverage) {
        super(beverage);
        this.beverage = beverage;
    }

    @Override
    public int getCost() {
        // sugar: $1
        return this.beverage.getCost() + 1;
    }

    @Override
    public String getDescription() {
        return this.beverage.getDescription() + "sugar + ";
    }
    
    
}
