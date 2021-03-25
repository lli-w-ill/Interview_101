package DesignPatterns.Chapter02_Creational_Design_Patterns.P1_Singleton_Pattern.Version3_Lazy_Version_with_Sync;

public class DatabaseConnector {
    
    // lazy version (preferred): instantiate whenever it is necessary
    private static DatabaseConnector INSTANCE;

    // make the constructor private so that it cannot be instantiated outside
    private DatabaseConnector() {

    }

    public static DatabaseConnector getInstance() {
        // lazy implementation  (preferred)
        // PROBLEM: IF WE HAVE MULTIPLE THREAD, THEN THERE WILL BE DIFFERENT INSTANCES RETURNED.
        if (INSTANCE == null) {
            INSTANCE = new DatabaseConnector();
        }
        return INSTANCE;
    }

    public void connect() {
        System.out.println("Connecting to the database...");
    }

    public void disconnect() {
        System.out.println("Disconnecting...");
    }
}
