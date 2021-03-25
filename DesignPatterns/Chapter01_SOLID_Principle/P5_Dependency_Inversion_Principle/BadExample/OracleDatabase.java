package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.BadExample;

// Low-leve module 2
public class OracleDatabase {
    
    public void connect() {
        System.out.println("Connecting to an Oracle database...");
    }

    public void disconnect() {
        System.out.println("Disconnecting the Oracle database...");
    }
}
