package DesignPatterns.Chapter02_Creational_Design_Patterns.P2_Factory_Pattern.Version2_Abstract_Factory_Pattern;

public class PetrolCarFactory implements AbstractFactory {
    
    @Override
    public Car getCar(String carType) {
        
        if (carType.equalsIgnoreCase("Ford")) {
            return new PetrolFord();
        } else if (carType.equalsIgnoreCase("Toyota")) {
            return new PetrolToyota();
        }

        return null;
    }
}
