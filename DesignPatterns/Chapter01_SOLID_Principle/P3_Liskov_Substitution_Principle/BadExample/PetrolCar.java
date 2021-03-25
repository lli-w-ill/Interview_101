package DesignPatterns.Chapter01_SOLID_Principle.P3_Liskov_Substitution_Principle.BadExample;

public class PetrolCar extends Vehicle {
    
    public PetrolCar(String type, int age) {
        super(type, age);
    }

    @Override
    protected void speedUp() {
        System.out.println("Pentral Car is speeding up...");
    }

    @Override
    protected void slowDown() {
        System.out.println("Pentral Car is slowing down...");
    }

    @Override
    // 加油
    protected void fuel() {
        System.out.println("Pentral Car fuel...");
    }

}
