package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example2;

public class Division implements Strategy {
    
    @Override
    public void execute(int num1, int num2) {
        // we should avoid division by 0 here
        System.out.println(num1 / num2);
    }

}
