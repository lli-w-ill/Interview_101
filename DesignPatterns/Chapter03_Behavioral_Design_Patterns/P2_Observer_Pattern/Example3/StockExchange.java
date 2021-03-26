package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example3;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.naming.ldap.Rdn;

public class StockExchange implements Subject {
    
    // stock price
    private float price = 100;
    // S(0) = $100 - a random walk
    private Random random;
    
    private List<Observer> observers;

    // aim: use observer pattern to monitor the stock prices at time S(t)
    // if S(t) > $105, then sell the stock
    // if S(t) < $95, then buy the stock
    @Override
    public void addObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void notifyAllObservers() {
        for (Observer observer : observers) {
            observer.update(price);
        }
    }

    public StockExchange() {
        random = new Random();
        observers = new ArrayList<>();
    }

    public void start() {

        while (true) {
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            // generate the next S(t+1) random stock price
            price = price + 2 * random.nextFloat() - 1;
            System.out.println(price);
            notifyAllObservers();
        }

    }

}
