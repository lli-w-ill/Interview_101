package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example3;

public class SellStockListener implements Observer {

    @Override
    public void update(float price) {
        if (price > 105) {
            System.out.println("Selling the stock because the S(t) > $105");
        }
    }
    
}
