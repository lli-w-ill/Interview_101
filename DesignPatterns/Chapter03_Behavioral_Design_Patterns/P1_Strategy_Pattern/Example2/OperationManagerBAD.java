package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example2;

// abstract layer in between the high-level modules and low-level modules
public class OperationManagerBAD {

    public void execute(Object o, int num1, int num2) {
        
        // PROBLEM: "design smell" ———— instanceof
        // PROBLEM: add else-if whenever a new operation is introduced
        if (o instanceof Addition) {
            ((Addition) o).execute(num1, num2);
        } else if (o instanceof Substraction) {
            ((Substraction) o).execute(num1, num2);
        } else if (o instanceof Multiplication) {
            ((Multiplication) o).execute(num1, num2);
        } else if (o instanceof Division) {
            ((Division) o).execute(num1, num2);
        }
    }
}
