package DesignPatterns.Chapter02_Creational_Design_Patterns.P2_Factory_Pattern.Version2_Abstract_Factory_Pattern;

public class FactoryProducer {
    
    public static AbstractFactory getFactory(String factory) {
        
        if (factory.equalsIgnoreCase("Electric")) {
            return new ElectricCarFactory();
        } else if (factory.equalsIgnoreCase("Petrol")) {
            return new PetrolCarFactory();
        }

        return null;
    }

}
