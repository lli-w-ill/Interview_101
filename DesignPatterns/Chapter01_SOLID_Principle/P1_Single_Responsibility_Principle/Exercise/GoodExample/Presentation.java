package DesignPatterns.Chapter01_SOLID_Principle.P1_Single_Responsibility_Principle.Exercise.GoodExample;

import java.util.List;

public class Presentation {
    
    public static void show(List<Integer> nums) {
        for (int num : nums) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
    
}
