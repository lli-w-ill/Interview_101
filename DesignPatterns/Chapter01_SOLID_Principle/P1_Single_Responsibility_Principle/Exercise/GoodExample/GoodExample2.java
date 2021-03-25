package DesignPatterns.Chapter01_SOLID_Principle.P1_Single_Responsibility_Principle.Exercise.GoodExample;

import java.util.List;

public class GoodExample2 {
    
    public static final int THRESHOLD = 5;

    public static void main(String[] args) {

        System.out.println("Welcome to the Application!");

        // get the input
        List<Integer> nums = InputProcessor.getInput(THRESHOLD);

        // sort
        Sorting.sort(nums);

        // show the result
        Presentation.show(nums);
    }

}
