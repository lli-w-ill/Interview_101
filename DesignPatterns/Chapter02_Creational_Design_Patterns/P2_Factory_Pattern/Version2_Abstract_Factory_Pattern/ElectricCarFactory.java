package DesignPatterns.Chapter02_Creational_Design_Patterns.P2_Factory_Pattern.Version2_Abstract_Factory_Pattern;

public class ElectricCarFactory implements AbstractFactory {
    
    @Override
    public Car getCar(String carType) {
        
        if (carType.equalsIgnoreCase("Ford")) {
            return new ElectricFord();
        } else if (carType.equalsIgnoreCase("Toyota")) {
            return new ElectricToyota();
        }

        return null;
    }

}
