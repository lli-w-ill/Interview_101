package DesignPatterns.Chapter01_SOLID_Principle.Single_Responsibility_Principle.Exercise.GoodExample;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class InputProcessor {
    
    public static List<Integer> getInput(int threshold) {
        
        Scanner scanner = new Scanner(System.in);

        List<Integer> nums = new ArrayList<>();

        System.out.println("Enter 5 valid integers in the range [0, 10]");

        while (nums.size() < threshold) {
            String s = scanner.nextLine();

            if (!ViolationChecker.isValid(s)) {
                System.out.println("Input is invalid...");
                continue;
            }

            nums.add(Integer.valueOf(s));
        }

        scanner.close();

        return nums;
    }

}
