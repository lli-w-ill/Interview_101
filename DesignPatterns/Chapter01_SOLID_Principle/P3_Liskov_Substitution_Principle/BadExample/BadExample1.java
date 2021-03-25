package DesignPatterns.Chapter01_SOLID_Principle.P3_Liskov_Substitution_Principle.BadExample;

public class BadExample1 {
 
    public static void main(String[] args) {

        Vehicle v = new Vehicle("Ford", 6);
        v.slowDown();
        v.speedUp();
        v.fuel();

        Vehicle p = new PetrolCar("Ford", 7);
        p.slowDown();
        p.speedUp();
        p.fuel();

        Vehicle e = new ElectricCar("Ford", 8);
        e.slowDown();
        e.speedUp();
        // e.fuel();   // "design smell", this breaks Liskov Substitution principle, we should re-consider the logic of implementation as far as inheritance is concerned. Vehicle is not a proper parent class

    }
    
}
