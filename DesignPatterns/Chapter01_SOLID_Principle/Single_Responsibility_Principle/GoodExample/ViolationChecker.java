package DesignPatterns.Chapter01_SOLID_Principle.Single_Responsibility_Principle.GoodExample;

public class ViolationChecker {
    
    // check whether the given pair contains valid numbers or not. Return true if pair components are numbers. Return false otherwise.
    public static boolean isValid(Pair pair) {

        String first = pair.getFirst();
        String second = pair.getSecond();

        try {
            Integer.parseInt(first);
        } catch (NumberFormatException nfe) {
            return false;
        }

        try {
            Integer.parseInt(second);
        } catch (NumberFormatException nfe) {
            return false;
        }

        return true;
    }
}
