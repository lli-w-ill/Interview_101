package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P6_NULL_Object_Pattern.Example1;

public class NullCustomer extends AbstractCustomer {

    @Override
    public boolean isNull() {
        return true;
    }

    @Override
    public String getCustomer() {
        return "No customer with the given name exists in the database...";
    }
    
}
