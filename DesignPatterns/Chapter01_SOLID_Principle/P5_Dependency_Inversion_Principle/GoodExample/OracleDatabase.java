package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.GoodExample;

public class OracleDatabase implements Database {

    @Override
    public void connect() {
        System.out.println("Connecting to an Oracle database...");
    }

    @Override
    public void disconnect() {
        System.out.println("Disconnecting the Oracle database...");
    }
    
}
