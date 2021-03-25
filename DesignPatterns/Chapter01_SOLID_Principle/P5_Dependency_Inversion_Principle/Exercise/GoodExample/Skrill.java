package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.Exercise.GoodExample;

// low-level module 3
public class Skrill implements PaymentMethod {

    @Override
    public void pay() {
        System.out.println("Paying with Skrill...");    
    }
    
}
