package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example3;

public class SmartphoneRenderer implements Renderer {
    
    @Override
    public void showImage() {
        System.out.println("Showing an image on smartphone...");
    }

}
