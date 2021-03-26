package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P5_Template_Pattern.Example2;

public class Football extends Sport {

    @Override
    protected void initializeGame() {
        System.out.println("Initializing a football game...");
    }

    @Override
    protected void playing() {
        System.out.println("Playing a football game...");
    }

    @Override
    protected void showResults() {
        System.out.println("Showing results of a football game...");
    }
    
}
