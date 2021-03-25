package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.GoodExample;

/**
 * Why this is good ?
 * Because high-level module knows nothing about low-level modules.
 */
public class GoodExample1 {
    
    public static void main(String[] args) {

        DatabaseController mysql = new DatabaseController(new MySQLDatabase());
        
        mysql.connect();
        mysql.disconnect();

        DatabaseController oracle = new DatabaseController(new OracleDatabase());

        oracle.connect();
        oracle.disconnect();
        
    }

}
