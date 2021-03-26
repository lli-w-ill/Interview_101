package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P5_Template_Pattern.Example2;

public abstract class Sport {
    
    protected abstract void initializeGame();
    protected abstract void playing();
    protected abstract void showResults();

    // Template Pattern
    public final void play() {
        initializeGame();
        playing();
        showResults();
    }

}
