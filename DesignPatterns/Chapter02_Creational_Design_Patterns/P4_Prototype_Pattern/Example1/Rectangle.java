package DesignPatterns.Chapter02_Creational_Design_Patterns.P4_Prototype_Pattern.Example1;

public class Rectangle extends Shape {
    
    public Rectangle(int width, int height) {
        super(width, height);
    }
    
    @Override
    public void draw() {
        System.out.println("Rectangle with width: " + width + ", height: " + height);
    }

    @Override
    public Shape cloneObject() {
        // this is the prototype apttern
        return new Rectangle(width, height);
    }

}
