package DesignPatterns.Chapter01_SOLID_Principle.P1_Single_Responsibility_Principle.BadExample;

import java.util.Scanner;

/**
 * This bad example (tight coupling) violates the single responsibility principle because there are multiple responsibilities (Scanner input, Convert input to integers, Mathmatical operation) within the main method
 */
public class BadExample1 {
    public static void main(String[] args) {
        System.out.println("Welcome to the Application!");

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the first number: ");
        String firstNumber = scanner.nextLine();

        System.out.println("Enter the second number: ");
        String secondNumber = scanner.nextLine();

        scanner.close();

        int firstInteger = 0;
        int secondInteger = 0;

        if (firstNumber == null) {
            System.out.println("First number is not valid...");
            return;
        }

        try {
            firstInteger = Integer.parseInt(firstNumber);
        } catch (NumberFormatException nfe) {
            System.out.println("First number is not valid...");
            return;
        }

        try {
            secondInteger = Integer.parseInt(secondNumber);
        } catch (NumberFormatException nfe) {
            System.out.println("Second number is not valid...");
            return;
        }

        int result = firstInteger + secondInteger;

        System.out.println("The result is: " + result);
        System.out.println("End of the application!");

    }
}

