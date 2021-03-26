package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P7_Visitor_Pattern.Example2;

public interface ShapeVisitor {
    
    public void visitCircle(Circle circle);
    public void visitRectangle(Rectangle rectangle);
    public void visitTriangle(Triangle triangle);

}
