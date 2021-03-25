package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.Exercise.BadExample;

import java.util.List;

public class SelectionSort implements SortingAlgorithm {
    
    public void selectSort(List<Integer> nums) {
        System.out.println("Selection sort is sorting the items...");
    }

}
