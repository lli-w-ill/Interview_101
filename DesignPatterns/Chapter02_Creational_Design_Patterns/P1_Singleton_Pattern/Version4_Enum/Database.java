package DesignPatterns.Chapter02_Creational_Design_Patterns.P1_Singleton_Pattern.Version4_Enum;

/**
 * Enums are compile-time constants, so it is guaranteed that this instance is thread safe.
 */
public enum Database {
    
    // acquiring the INSTANCE is thread safe by default
    INSTANCE;

    public void connect() {
        System.out.println("Connecting to the database...");
    }

    public void disconnect() {
        System.out.println("Disconnecting...");
    }
}
