package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example1;

// abstract layer in between the high-level modules and low-level modules
public class OperationManager {
    
    // Principle 3: favor composition than inheritance
    // BECAUSE THE BEHAVIOR CAN BE CHANGED AT RUN-TIME
    private Strategy strategy;

    public void setStrategy(Strategy strategy) {
        this.strategy = strategy;
    }

    public void execute(int num1, int num2) {
        // OperationManager doesn't know which strategy at all
        this.strategy.execute(num1, num2);
    }
}
