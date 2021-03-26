package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example3;

public class BuyStockListener implements Observer {

    @Override
    public void update(float price) {
        if (price < 95) {
            System.out.println("Buying stock because the S(t) < $95");
        }
    }
    
}
