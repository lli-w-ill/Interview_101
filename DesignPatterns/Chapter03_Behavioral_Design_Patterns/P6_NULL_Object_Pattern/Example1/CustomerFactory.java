package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P6_NULL_Object_Pattern.Example1;

public class CustomerFactory {
    
    private Database database;

    public CustomerFactory() {
        this.database = new Database();
    }

    public AbstractCustomer getCustomer(String name) {
        if (checkName(name)) {
            return new RealCustomer(name);
        }
        
        return new NullCustomer();
    }

    public boolean checkName(String name) {
        if (database.existCustomer(name)) {
            return true;
        }
        return false;
    }

}
