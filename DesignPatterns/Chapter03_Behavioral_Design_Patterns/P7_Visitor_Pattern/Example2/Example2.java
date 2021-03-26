package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P7_Visitor_Pattern.Example2;

import java.util.ArrayList;
import java.util.List;

public class Example2 {
    
    public static void main(String[] args) {

        List<Shape> shapes = new ArrayList<>();
        shapes.add(new Circle(3.1));
        shapes.add(new Triangle(1, 2, 3.4));
        shapes.add(new Rectangle(5.1, 4.2));

        ShapeVisitor save = new SaveCSVFile();

        for (Shape shape : shapes) {
            shape.accept(save);
        }
        
    }

}
