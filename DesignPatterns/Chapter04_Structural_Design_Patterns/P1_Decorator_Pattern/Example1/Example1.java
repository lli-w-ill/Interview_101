package DesignPatterns.Chapter04_Structural_Design_Patterns.P1_Decorator_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {

        Beverage b = new Sugar(new Milk(new PlainBeverage()));
        
        System.out.println(b.getCost());
        System.out.println(b.getDescription());

        // change behavior at run-time: double sugar and milk
        Beverage b2 = new Sugar(new Sugar(new Milk(new Milk(new PlainBeverage()))));

        System.out.println(b2.getCost());
        System.out.println(b2.getDescription());

    }

}
