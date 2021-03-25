package DesignPatterns.Chapter01_SOLID_Principle.P3_Liskov_Substitution_Principle.GoodExample;

public class ElectricCar extends Vehicle {
    
    public ElectricCar(String type, int age) {
        super(type, age);
    }

    @Override
    protected void speedUp() {
        System.out.println("Electric Car is speeding up...");
    }

    @Override
    protected void slowDown() {
        System.out.println("Electric Car is slowing down...");
    }

    @Override
    protected void fuel() {
        System.out.println("Electric car is being charged...");
    }

}
