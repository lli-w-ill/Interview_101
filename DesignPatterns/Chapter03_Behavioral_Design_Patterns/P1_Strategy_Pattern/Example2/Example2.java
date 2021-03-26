package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example2;

public class Example2 {
    
    public static void main(String[] args) {

        OperationManagerBAD manager = new OperationManagerBAD();
        manager.execute(new Addition(), 10, 5);

        manager.execute(new Multiplication(), 10, 8);

        manager.execute(new Substraction(), 10, 3);

        manager.execute(new Division(), 10, 2);
        
    }

}
