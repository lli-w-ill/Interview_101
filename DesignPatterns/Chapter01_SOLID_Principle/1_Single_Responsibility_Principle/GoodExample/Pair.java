package DesignPatterns.Chapter01_SOLID_Principle.Single_Responsibility_Principle.GoodExample;

public class Pair {

    private String first;
    private String second;

    public Pair(String first, String second) {
        this.first = first;
        this.second = second;
    }

    public String getFirst() {
        return first;
    }

    public String getSecond() {
        return second;
    }
 
}
