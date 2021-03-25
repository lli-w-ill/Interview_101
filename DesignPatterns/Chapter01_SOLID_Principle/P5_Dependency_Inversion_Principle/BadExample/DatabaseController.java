package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.BadExample;

// High-level module
public class DatabaseController {
    
    /**
     * Problem:
     * If MySQLDatabase (low-level module 1) is very different from OracleDatabase (low-level module 2), then lots of changes have to be made
     */
    // use low-level module in high-level module
    // private MySQLDatabase database;
    private OracleDatabase database;

    public DatabaseController() {
        // tight binding (violation)
        // we should avoid it using an interface
        // database = new MySQLDatabase();
        database = new OracleDatabase();
        database.connect();
        database.disconnect();
    }
}
