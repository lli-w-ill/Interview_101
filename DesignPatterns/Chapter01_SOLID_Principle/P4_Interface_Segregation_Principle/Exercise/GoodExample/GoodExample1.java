package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.Exercise.GoodExample;

public class GoodExample1 {
    
    public static void main(String[] args) {

        ICEO ceo = new CEO();

        ceo.addBonus();
        ceo.salary();
        ceo.makeDecisions();
        ceo.addStocks();

        IManager manager = new Manager();

        manager.addBonus();
        manager.hire();
        manager.train();
        manager.salary();

        IEmployee employee = new Employee();

        employee.salary();
        
    }

}
