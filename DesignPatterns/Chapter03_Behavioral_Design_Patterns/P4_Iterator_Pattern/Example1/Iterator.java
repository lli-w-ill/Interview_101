package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P4_Iterator_Pattern.Example1;

public interface Iterator {
    
    // return true if there is next element, return false otherwise
    public boolean hashNext();

    // get the next element
    public Object next();

}
