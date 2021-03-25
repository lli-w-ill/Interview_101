package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.Exercise.GoodExample;

import java.util.List;

public class BucketSort implements SortingAlgorithm {
    
    @Override
    public void sort(List<Integer> nums) {
        System.out.println("Bucket sort is sorting the items...");
    }

}
