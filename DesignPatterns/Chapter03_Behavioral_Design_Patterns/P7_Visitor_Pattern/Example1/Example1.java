package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P7_Visitor_Pattern.Example1;

import java.util.ArrayList;
import java.util.List;

// In Example 1, we extract the common operation getPrice into a unique class
public class Example1 {
    
    public static void main(String[] args) {

        List<ShoppingItem> items = new ArrayList<>();

        items.add(new Table("dinner desk", 20));
        items.add(new Table("study desk", 45));
        items.add(new Chair("table chair", 10));
        items.add(new Chair("bench", 15));
     
        double sum = 0;
        ShoppingCartVisitor shoppingCart = new ShoppingCart();

        for (ShoppingItem shoppingItem : items) {
            sum += shoppingItem.accept(shoppingCart);
        }

        System.out.println(sum);
    }

}
