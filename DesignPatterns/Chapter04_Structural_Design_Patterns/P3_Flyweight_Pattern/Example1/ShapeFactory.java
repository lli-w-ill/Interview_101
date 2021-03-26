package DesignPatterns.Chapter04_Structural_Design_Patterns.P3_Flyweight_Pattern.Example1;

import java.util.HashMap;
import java.util.Map;

public class ShapeFactory {
    
    // we will create a rectangle for every color, and reuse rectangles with the same color
    // key: color
    // value: Rectangle object
    private Map<String, Shape> shapes;

    public ShapeFactory() {
        shapes = new HashMap<>();
    }

    // get a shape based on a given color
    public Shape getShape(String color) {
        
        if (shapes.containsKey(color)) {
            return shapes.get(color);
        }

        // instantiate a new shape
        System.out.println("Creating a new rectangle...");
        Shape shape = new Rectangle(color);
        shapes.put(color, shape);
        return shape;
    }

}
