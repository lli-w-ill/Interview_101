package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.Exercise.BadExample;

/**
 * This is a "fat interface"
 */
public interface IEmployee {
    
    // CEO + managers + workers
    public void salary();

    // managers
    public void hire();
    public void train();

    // CEO + managers
    public void addBonus();

    // CEO
    public void makeDecisions();
    public void addStocks();

}
