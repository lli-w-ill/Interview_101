package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P1_Strategy_Pattern.Example2;

// abstraction
// dependency inversion principle: high-level components don't reply on low-level components, but both high-level and low-level depend on abstraction
public interface Strategy {

    public void execute(int nums1, int num2);
    
}
