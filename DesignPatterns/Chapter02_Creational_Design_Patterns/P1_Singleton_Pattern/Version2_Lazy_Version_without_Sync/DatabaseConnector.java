package DesignPatterns.Chapter02_Creational_Design_Patterns.P1_Singleton_Pattern.Version2_Lazy_Version_without_Sync;

public class DatabaseConnector {
    
    // lazy version (preferred): instantiate whenever it is necessary
    private static DatabaseConnector INSTANCE;

    // make the constructor private so that it cannot be instantiated outside
    // PROBLEM: NEW INSTANCES CAN BE INSTANTIATED WITH THE HELP OF "REFLECTION ATTACK"
    private DatabaseConnector() {

    }

    public static DatabaseConnector getInstance() {
        // lazy implementation  (preferred)
        if (INSTANCE == null) {
            // this block can be entered by a single thread
            // PROBLEM: IT IS TOO SLOW
            synchronized(DatabaseConnector.class) {
                INSTANCE = new DatabaseConnector();
            }
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
