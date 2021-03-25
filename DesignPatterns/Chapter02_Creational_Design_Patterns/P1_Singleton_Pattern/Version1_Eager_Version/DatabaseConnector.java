package DesignPatterns.Chapter02_Creational_Design_Patterns.P1_Singleton_Pattern.Version1_Eager_Version;

public class DatabaseConnector {
    
    // eager version: instantiate the DatabaseConnector no matter what we are going to use it or not
    private static DatabaseConnector INSTANCE = new DatabaseConnector();

    // make the constructor private so that it cannot be instantiated outside
    private DatabaseConnector() {

    }

    public static DatabaseConnector getInstance() {
        return INSTANCE;
    }

    public void connect() {
        System.out.println("Connecting to the database...");
    }

    public void disconnect() {
        System.out.println("Disconnecting...");
    }
}
