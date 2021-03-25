package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.Exercise.GoodExample;

public class CEO implements ICEO {

    @Override
    public void addBonus() {
        System.out.println("Getting the bonus at the end of the year...");
    }

    @Override
    public void addStocks() {
        System.out.println("Getting shares of the company as bonus...");
    }

    @Override
    public void makeDecisions() {
        System.out.println("Making decisions...");
    }

    @Override
    public void salary() {
        System.out.println("Getting the salary...");
    }
    
}
