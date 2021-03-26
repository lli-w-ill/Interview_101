package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P6_NULL_Object_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {

        CustomerFactory customerFactory = new CustomerFactory();

        System.out.println(customerFactory.getCustomer("Joe").getCustomer());
        
        // this will not get a NullPointerException
        System.out.println(customerFactory.getCustomer("Jack").getCustomer());

    }

}
