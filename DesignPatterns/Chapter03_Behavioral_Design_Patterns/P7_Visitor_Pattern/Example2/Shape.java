package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P7_Visitor_Pattern.Example2;

public interface Shape {
    
    public void accept(ShapeVisitor visitor);
    
}
