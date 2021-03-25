package DesignPatterns.Chapter02_Creational_Design_Patterns.P2_Factory_Pattern.Version2_Abstract_Factory_Pattern;

public class Example2 {
    
    public static void main(String[] args) {
        
        AbstractFactory electric = FactoryProducer.getFactory("Electric");
        electric.getCar("Ford").assemble();
        electric.getCar("Toyota").assemble();
    
        AbstractFactory petrol = FactoryProducer.getFactory("Petrol");
        petrol.getCar("Ford").assemble();
        petrol.getCar("Toyota").assemble();

    }

}
