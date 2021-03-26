package DesignPatterns.Chapter04_Structural_Design_Patterns.P2_Facade_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {

        SortingManager manager = new SortingManager();
        manager.doBubbleSort();
        manager.doMergeSort();
        manager.doQuickSort();
        
    }

}
