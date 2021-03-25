package DesignPatterns.Chapter02_Creational_Design_Patterns.P4_Prototype_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {
        
        Shape square = new Square(10, 5);
        square.draw();

        Shape squareClone = square.cloneObject();
        squareClone.draw();

        if (square == squareClone) {
            System.out.println("They are the same...");
        } else {
            System.out.println("They are different...");
        }
        
    }

}
