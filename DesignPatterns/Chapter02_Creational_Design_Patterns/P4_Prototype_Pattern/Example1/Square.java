package DesignPatterns.Chapter02_Creational_Design_Patterns.P4_Prototype_Pattern.Example1;

public class Square extends Shape {

    public Square(int width, int height) {
        super(width, height);
    }
    
    @Override
    public void draw() {
        System.out.println("Square with width: " + width + ", height: " + height);
    }

    @Override
    public Shape cloneObject() {
        // this is the prototype apttern
        return new Square(width, height);
    }
    
}
