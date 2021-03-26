package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P4_Iterator_Pattern.Example1;

// store the names
public class NameRepository {
    
    private String[] names = {"Adam", "Joe", "John", "Sarah"};

    public Iterator getIterator() {
        return new NameIterator(names);
    }

    
}
