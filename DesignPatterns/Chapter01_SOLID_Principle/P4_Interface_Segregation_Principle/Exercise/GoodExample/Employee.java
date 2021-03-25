package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.Exercise.GoodExample;

public class Employee implements IEmployee {
    
    @Override
    public void salary() {
        System.out.println("Getting the salary...");
    }
}
