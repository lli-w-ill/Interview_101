package DesignPatterns.Chapter06_Service_Locator_Pattern.Example1;

// Service 1: Database
public class DatabaseService implements Service {

    public static final String NAME = "database service";

    @Override
    public String getName() {
        return DatabaseService.NAME;
    }
    
    @Override
    public void execute() {
        System.out.println("Executing database service...");
    }

}
