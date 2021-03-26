package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Example3 {
    
    public static void main(String[] args) {

        List<String> namesList = new ArrayList<>();
        namesList.add("Adam");
        namesList.add("Kevin");
        namesList.add("Ada");
        namesList.add("Joe");

        // 另一种方法 (Adapter Pattern) : asList 是一个 adapter，因为 List<String> 和 String[] 是两种不同的实现方法
        String[] names = {"Adam", "Kevin", "Ada", "Joe"};
        List<String> namesList2 = Arrays.asList(names);

        for (String s : namesList2) {
            System.out.println(s);
        }

    }

}
