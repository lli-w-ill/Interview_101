package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.Exercise.GoodExample;

// low-level module 1
public class Payoneer implements PaymentMethod {

    @Override
    public void pay() {
        System.out.println("Paying with Payoneer...");    
    }
    
}
