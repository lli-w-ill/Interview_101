package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example3;

public interface Subject {
    
    public void addObserver(Observer o);

    public void notifyAllObservers();
}
