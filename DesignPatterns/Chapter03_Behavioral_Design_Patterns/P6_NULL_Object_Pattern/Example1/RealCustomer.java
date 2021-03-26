package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P6_NULL_Object_Pattern.Example1;

public class RealCustomer extends AbstractCustomer {

    private String customerName;

    public RealCustomer(String customerName) {
        this.customerName = customerName;
    }

    @Override
    public boolean isNull() {
        return false;
    }

    @Override
    public String getCustomer() {
        return customerName;
    }

}
