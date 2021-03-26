package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example3;

public class ImageManager {
    
    // abstraction, know nothing about low-level implementataion
    private Renderer renderer;

    public void setStrategy(Renderer renderer) {
        this.renderer = renderer;
    }

    public void show() {
        renderer.showImage();
    }

    public void showBAD() {
        if (renderer instanceof TVRenderer) {
            TVRenderer tvRenderer = (TVRenderer) renderer;
            tvRenderer.showImage();
        } else if (renderer instanceof LaptopRenderer) {
            LaptopRenderer laptopRenderer = (LaptopRenderer) renderer;
            laptopRenderer.showImage();
        } else if (renderer instanceof SmartphoneRenderer) {
            SmartphoneRenderer smartphoneRenderer = (SmartphoneRenderer) renderer;
            smartphoneRenderer.showImage();
        }
    }

}
