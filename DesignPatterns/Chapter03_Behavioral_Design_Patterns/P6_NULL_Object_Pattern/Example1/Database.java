package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P6_NULL_Object_Pattern.Example1;

import java.util.ArrayList;
import java.util.List;

public class Database {
    
    private List<String> customerNames;
    
    public Database() {
        this.customerNames = new ArrayList<>();

        // add fake data
        this.customerNames.add("Daniel");
        this.customerNames.add("Adam");
        this.customerNames.add("Joe");
        this.customerNames.add("Michael");
        this.customerNames.add("Andrew");
        this.customerNames.add("John");
    }

    public boolean existCustomer(String name) {
        
        for (String s : customerNames) {
            if (s.equals(name)) {
                return true;
            }
        }
        
        return false;
    }
}
