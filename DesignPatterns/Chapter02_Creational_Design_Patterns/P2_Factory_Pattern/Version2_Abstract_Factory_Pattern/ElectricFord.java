package DesignPatterns.Chapter02_Creational_Design_Patterns.P2_Factory_Pattern.Version2_Abstract_Factory_Pattern;

public class ElectricFord implements Car {
    
    @Override
    public void assemble() {
        System.out.println("Assembling an electric Ford...");
    }

}
