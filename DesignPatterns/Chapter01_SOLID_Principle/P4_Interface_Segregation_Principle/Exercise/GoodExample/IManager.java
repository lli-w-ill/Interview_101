package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.Exercise.GoodExample;

public interface IManager extends IEmployee {
    
    public void hire();

    public void train();

    public void addBonus();

}
