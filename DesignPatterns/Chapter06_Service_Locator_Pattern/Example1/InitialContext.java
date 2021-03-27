package DesignPatterns.Chapter06_Service_Locator_Pattern.Example1;

public class InitialContext {
    
    // return the service handler for jndiName service
    public Object lookup(String jndiName) {
        
        switch (jndiName) {
            case DatabaseService.NAME:
                return new DatabaseService();
            case MessagingService.NAME:
                return new MessagingService();
            default:
                return null;
        }

    }

}
