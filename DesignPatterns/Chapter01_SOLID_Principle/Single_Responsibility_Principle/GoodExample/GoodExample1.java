package DesignPatterns.Chapter01_SOLID_Principle.Single_Responsibility_Principle.GoodExample;

/**
 * This is a good example (loosely coupling). Behaviors are separated in different classes.
 */
public class GoodExample1 {
    
    public static void main(String[] args) {
        
        System.out.println("Welcome to the Application!");

        // get the values from InputProcessor
        Pair pair = InputProcessor.process();

        // check whether the inputs are convertable to integers
        if (!ViolationChecker.isValid(pair)) {
            System.out.println("One of the input is invalid...");
            return;
        }

        int firstInteger = Integer.parseInt(pair.getFirst());
        int secondInteger = Integer.parseInt(pair.getSecond());

        // mathmatical operation
        int result = Operation.execute(firstInteger, secondInteger);

        // present the result
        Presentation.present(result);

        System.out.println("End of the application!");
    }
}
