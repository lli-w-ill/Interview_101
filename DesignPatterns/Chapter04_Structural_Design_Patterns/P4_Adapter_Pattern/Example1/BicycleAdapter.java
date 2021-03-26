package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example1;

public class BicycleAdapter implements Vehicle {
    
    private Bicycle bicycle;

    public BicycleAdapter(Bicycle bicycle) {
        this.bicycle = bicycle;
    }

    @Override
    public void accelerate() {
        this.bicycle.go();
    }

}
