package DesignPatterns.Chapter01_SOLID_Principle.P3_Liskov_Substitution_Principle.GoodExample;

public abstract class Vehicle {
    
    protected String type;
    protected int age;

    public Vehicle(String type, int age) {
        this.type = type;
        this.age = age;
    }

    protected void speedUp() {
        System.out.println("Vehicle is speeding up...");
    }

    protected void slowDown() {
        System.out.println("Vehicle is slowing down...");
    }

    // let child class decide how to implement it
    protected abstract void fuel();

}
