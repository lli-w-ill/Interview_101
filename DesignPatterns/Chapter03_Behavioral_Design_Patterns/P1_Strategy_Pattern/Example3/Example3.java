package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example3;

public class Example3 {
    
    public static void main(String[] args) {

        ImageManager manager = new ImageManager();
        manager.setStrategy(new LaptopRenderer());
        manager.show();
        manager.showBAD();

        manager.setStrategy(new SmartphoneRenderer());
        manager.show();
        manager.showBAD();

        manager.setStrategy(new TVRenderer());
        manager.show();
        manager.showBAD();

    }

}
