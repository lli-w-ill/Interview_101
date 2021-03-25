package DesignPatterns.Chapter01_SOLID_Principle.P3_Liskov_Substitution_Principle.GoodExample1;

public class GoodExample1 {
 
    public static void main(String[] args) {

        // Vehicle is an abstract class
        // Vehicle v = new Vehicle("Ford", 6);
        // v.slowDown();
        // v.speedUp();
        // v.fuel();

        Vehicle p = new PetrolCar("Ford", 7);
        p.slowDown();
        p.speedUp();
        p.fuel();

        Vehicle e = new ElectricCar("Ford", 8);
        e.slowDown();
        e.speedUp();
        e.fuel(); 

    }
    
}
