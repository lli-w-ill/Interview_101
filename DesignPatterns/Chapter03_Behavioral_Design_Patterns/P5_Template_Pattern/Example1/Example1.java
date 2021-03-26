package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P5_Template_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {
        
        int[] nums = {1, 5, 3, -2, 10, 12, 8, 5, 6};

        Algorithm bubble = new BubbleSort(nums);
        bubble.sort();

        Algorithm select = new SelectionSort(nums);
        select.sort();
        
    }

}
