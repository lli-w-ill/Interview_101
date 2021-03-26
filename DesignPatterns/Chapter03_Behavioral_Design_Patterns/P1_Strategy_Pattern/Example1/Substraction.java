package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example1;

public class Substraction implements Strategy {
    
    @Override
    public void execute(int num1, int num2) {
        System.out.println(num1 - num2);
    }

}
