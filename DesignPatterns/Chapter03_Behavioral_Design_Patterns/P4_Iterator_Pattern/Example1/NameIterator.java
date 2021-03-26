package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P4_Iterator_Pattern.Example1;

public class NameIterator implements Iterator {

    private String[] names;
    private int index;

    public NameIterator(String[] names) {
        this.names = names;
    }

    @Override
    public boolean hashNext() {
        return index < this.names.length;
    }

    @Override
    public Object next() {
        if (hashNext()) {
            return this.names[index++];
        }
        return null;
    }
    
    
}
