package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P7_Visitor_Pattern.Example1;

public interface ShoppingItem {
    
    public double accept(ShoppingCartVisitor visitor);

}
