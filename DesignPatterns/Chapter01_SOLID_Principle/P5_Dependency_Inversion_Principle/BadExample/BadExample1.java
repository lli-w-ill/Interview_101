package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.BadExample;

/**
 * Problem: High-level module is directly depending on the low-level module. If low-level module is changed, high-level module has to be changed.
 */
public class BadExample1 {
    
    public static void main(String[] args) {

        new DatabaseController();

    }

}
