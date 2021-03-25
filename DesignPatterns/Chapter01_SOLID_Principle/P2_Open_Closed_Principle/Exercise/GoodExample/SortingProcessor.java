package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.Exercise.GoodExample;

import java.util.List;

public class SortingProcessor {
    
    public static void execute(SortingAlgorithm algorithm, List<Integer> nums) {
        algorithm.sort(nums);
    }

}
