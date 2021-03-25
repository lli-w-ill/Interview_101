package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.BadExample;

// Low-level module 1
public class MySQLDatabase {
    
    public void connect() {
        System.out.println("Connecting to a MySQL database...");
    }

    public void disconnect() {
        System.out.println("Disconnecting to MySQL database...");
    }

}
