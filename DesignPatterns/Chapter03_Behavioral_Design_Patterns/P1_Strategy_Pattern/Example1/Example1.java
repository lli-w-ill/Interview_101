package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {

        OperationManager manager = new OperationManager();
        manager.setStrategy(new Addition());
        manager.execute(10, 5);

        manager.setStrategy(new Multiplication());
        manager.execute(10, 8);

        manager.setStrategy(new Substraction());
        manager.execute(10, 3);

        manager.setStrategy(new Division());
        manager.execute(10, 2);
        
    }

}
