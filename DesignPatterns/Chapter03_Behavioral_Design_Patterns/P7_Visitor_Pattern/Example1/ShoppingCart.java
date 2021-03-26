package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P7_Visitor_Pattern.Example1;

public class ShoppingCart implements ShoppingCartVisitor {

    @Override
    public double visit(Table table) {
        return table.getPrice();
    }

    @Override
    public double visit(Chair chair) {
        return chair.getPrice();
    }
    
}
