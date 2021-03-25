package DesignPatterns.Chapter02_Creational_Design_Patterns.P2_Factory_Pattern.Version1_Factory_Pattern;

public class AnimalFactory {
    
    public static Animal getAnimal(AnimalType type) {
        
        // this is true but
        // PROBLEM: HIGH CYCLOMATIC COMPLEXITY, DIFFICULT TO TEST FACTORY PATTERN
        if (type == AnimalType.CAT) {
            return new Cat();
        } else if (type == AnimalType.DOG) {
            return new Dog();
        } else if (type == AnimalType.LION) {
            return new Lion();
        } else if (type == AnimalType.TIGER) {
            return new Tiger();
        }

        return null;
    }

}
