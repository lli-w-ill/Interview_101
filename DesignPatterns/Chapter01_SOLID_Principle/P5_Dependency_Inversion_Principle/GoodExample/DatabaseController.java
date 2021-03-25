package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.GoodExample;

// High-level module
public class DatabaseController {
    
    // the type is of an interface, so we achieve loosely coupled architecture
    private Database database;

    public DatabaseController(Database database) {
        this.database = database;
    }

    public void connect() {
        this.database.connect();
    }

    public void disconnect() {
        this.database.disconnect();
    }

}
