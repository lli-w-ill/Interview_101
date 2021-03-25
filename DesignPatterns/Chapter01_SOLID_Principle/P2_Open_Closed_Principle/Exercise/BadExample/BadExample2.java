package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.Exercise.BadExample;

import java.util.ArrayList;
import java.util.Arrays;

public class BadExample2 {
    
    public static void main(String[] args) {

        SortingProcessor.execute(new MergeSort(), new ArrayList<Integer>(Arrays.asList(3, 5, 1)));

        SortingProcessor.execute(new SelectionSort(), new ArrayList<Integer>(Arrays.asList(3, 5, 1)));

        SortingProcessor.execute(new InsertionSort(), new ArrayList<Integer>(Arrays.asList(3, 5, 1)));
        
    }

}
