package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P7_Visitor_Pattern.Example1;

public interface ShoppingCartVisitor {
    
    public double visit(Table table);

    public double visit(Chair chair);

}
