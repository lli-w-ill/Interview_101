package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P5_Template_Pattern.Example2;

public class Basketball extends Sport {
    
    @Override
    protected void initializeGame() {
        System.out.println("Initializing a basketball game...");
    }

    @Override
    protected void playing() {
        System.out.println("Playing a basketball game...");
    }

    @Override
    protected void showResults() {
        System.out.println("Showing results of a basketball game...");
    }

}
