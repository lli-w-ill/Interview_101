package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P7_Visitor_Pattern.Example2;

public class SaveCSVFile implements ShapeVisitor {

    @Override
    public void visitCircle(Circle circle) {
        System.out.println("Saving the circle: radius = " + circle.getRadius());
    }

    @Override
    public void visitRectangle(Rectangle rectangle) {
        System.out.println("Saving the rectangle: width = " + rectangle.getWidth() + ", height = " + rectangle.getHeight());
    }

    @Override
    public void visitTriangle(Triangle triangle) {
        System.out.println("Saving the triangle: side1 = " + triangle.getSide1() + ", side2 = " + triangle.getSide2() + ", side3 = " + triangle.getSide3());
    }
    
}
