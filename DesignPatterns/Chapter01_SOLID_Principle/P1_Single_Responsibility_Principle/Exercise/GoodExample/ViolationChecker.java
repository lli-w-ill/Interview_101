package DesignPatterns.Chapter01_SOLID_Principle.P1_Single_Responsibility_Principle.Exercise.GoodExample;

public class ViolationChecker {
    
    public static boolean isValid(String input) {
        try {
            Integer.parseInt(input);
        } catch (NumberFormatException nfe) {
            return false;
        }

        int num = Integer.parseInt(input);

        if (num < 0 || num > 10) {
            return false;
        }

        return true;
    }

}
