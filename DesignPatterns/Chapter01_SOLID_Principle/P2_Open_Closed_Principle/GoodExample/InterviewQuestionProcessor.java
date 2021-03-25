package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.GoodExample;

public class InterviewQuestionProcessor {
    
    public static void process(InterviewQuestion question) {
        
        // this is a typical implementation of the loosely coupled system
        // this class konw NOTHING about the question and its type!
        // this is PURE ABSTRACTION
        question.execute();

    }

}
