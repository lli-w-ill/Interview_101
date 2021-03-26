package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example3;

public class Example3 {
    
    public static void main(String[] args) {
        StockExchange stockExchange = new StockExchange();

        stockExchange.addObserver(new BuyStockListener());
        stockExchange.addObserver(new SellStockListener());
        
        stockExchange.start();
    }

}
