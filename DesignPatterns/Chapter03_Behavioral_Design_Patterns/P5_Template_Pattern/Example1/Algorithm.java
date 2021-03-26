package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P5_Template_Pattern.Example1;

public abstract class Algorithm {
    
    protected int[] nums;

    public Algorithm(int[] nums) {
        this.nums = nums;
    }

    protected abstract void initialize();
    protected abstract void sorting();
    protected abstract void showResult();

    protected void swap(int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Template Pattern
    // make sure this template will not be overriden by subclasses
    public final void sort() {
        initialize();
        sorting();
        showResult();
    }

}
