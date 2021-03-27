package DesignPatterns.Chapter06_Service_Locator_Pattern.Example1;

// Service 2: Messaging
public class MessagingService implements Service {
    
    public static final String NAME = "messaging service";

    @Override
    public String getName() {
        return MessagingService.NAME;
    }
    
    @Override
    public void execute() {
        System.out.println("Executing messaging service...");
    }

}
