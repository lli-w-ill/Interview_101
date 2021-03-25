package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.GoodExample;

// Abstract layer
public interface Database {
    
    public void connect();

    public void disconnect();
    
}
