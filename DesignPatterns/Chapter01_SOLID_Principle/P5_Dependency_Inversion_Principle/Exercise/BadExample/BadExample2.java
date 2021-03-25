package DesignPatterns.Chapter01_SOLID_Principle.P5_Dependency_Inversion_Principle.Exercise.BadExample;

public class BadExample2 {
 
    public static void main(String[] args) {
        WebStore store = new WebStore();
        store.purchaseItem();
    }
    
}
