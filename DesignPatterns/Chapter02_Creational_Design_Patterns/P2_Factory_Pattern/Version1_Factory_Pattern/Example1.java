package DesignPatterns.Chapter02_Creational_Design_Patterns.P2_Factory_Pattern.Version1_Factory_Pattern;

public class Example1 {
    
    public static void main(String[] args) {
        
        // This is bad
        Animal bad = new Cat();
        // because if in the future we want to change AmericanCat, we need to change the line to `Animal bad = new AmericanCat();`
        // but if we use factory, we only need to add an enum and change the line to `Animal cat = AnimalFactory.getAnimal(AnimalType.AmericanCat);`


        // get a Cat object
        Animal cat = AnimalFactory.getAnimal(AnimalType.CAT);
        cat.eat();

        // get a Dog object
        Animal dog = AnimalFactory.getAnimal(AnimalType.DOG);
        dog.eat();
    }

}
