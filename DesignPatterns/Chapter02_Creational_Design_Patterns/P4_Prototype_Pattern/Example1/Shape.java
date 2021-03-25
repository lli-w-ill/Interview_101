package DesignPatterns.Chapter02_Creational_Design_Patterns.P4_Prototype_Pattern.Example1;

public abstract class Shape {
    
    protected int width;
    protected int height;

    public Shape(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public abstract void draw();
    public abstract Shape cloneObject();

}
