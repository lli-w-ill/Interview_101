package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.GoodExample;

// Low-level module 1
public class MySQLDatabase implements Database {

    @Override
    public void connect() {
        System.out.println("Connecting to a MySQL database...");
    }

    @Override
    public void disconnect() {
        System.out.println("Disconnecting to MySQL database...");
    }
    
}
