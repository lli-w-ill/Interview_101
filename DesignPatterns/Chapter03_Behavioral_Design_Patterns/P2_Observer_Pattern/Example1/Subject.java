package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example1;

public interface Subject {
    
    public void addObserver(Observer o);

    public void removeObserver(Observer o);

    public void notifyAllObservers();

}
