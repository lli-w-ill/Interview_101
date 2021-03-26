package DesignPatterns.Chapter04_Structural_Design_Patterns.P2_Facade_Pattern.Example1;

public class SortingManager {
    
    // use superclass type instead of subclasses
    private Algorithm bubbleSort;
    private Algorithm mergeSort;
    private Algorithm quickSort;

    public SortingManager() {
        this.bubbleSort = new BubbleSort();
        this.mergeSort = new MergeSort();
        this.quickSort = new QuickSort();
    }

    public void doBubbleSort() {
        this.bubbleSort.sort();
    }

    public void doMergeSort() {
        this.mergeSort.sort();
    }

    public void doQuickSort() {
        this.quickSort.sort();
    }
    
}
