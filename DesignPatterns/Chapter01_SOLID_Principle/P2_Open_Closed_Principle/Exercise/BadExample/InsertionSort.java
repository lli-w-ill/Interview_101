package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.Exercise.BadExample;

import java.util.List;

public class InsertionSort implements SortingAlgorithm {
    
    public void insertSort(List<Integer> nums) {
        System.out.println("Insertion sort is sorting the items...");
    }
    
}
