package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.Exercise.BadExample;

import java.util.List;

public class SortingProcessor {
    
    public static void execute(SortingAlgorithm algorithm, List<Integer> nums) {
        
        if (algorithm instanceof InsertionSort) {
            InsertionSort is = (InsertionSort) algorithm;
            is.insertSort(nums);
        } else if (algorithm instanceof MergeSort) {
            MergeSort ms = (MergeSort) algorithm;
            ms.mergeSort(nums);
        } else if (algorithm instanceof SelectionSort) {
            SelectionSort ss = (SelectionSort) algorithm;
            ss.selectSort(nums);
        }
        
    }

}
