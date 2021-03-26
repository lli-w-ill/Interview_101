package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {

        Vehicle bus = new Bus();
        Vehicle car = new Car();
        // Vehicle bicycle = new Bicycle();    // error
        Vehicle bicycle = new BicycleAdapter(new Bicycle());

        bus.accelerate();
        car.accelerate();
        bicycle.accelerate();
        
    }

}
