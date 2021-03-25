package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.Exercise.GoodExample;

public class Manager implements IManager {

    @Override
    public void addBonus() {
        System.out.println("Adding bonus at the end of the year...");
    }

    @Override
    public void hire() {
        System.out.println("Hiring the employees...");
    }

    @Override
    public void train() {
        System.out.println("Training the employees...");
    }

    @Override
    public void salary() {
        System.out.println("Getting the salary...");
    }
    
    
}
