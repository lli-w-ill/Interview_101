package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.GoodExample;

public class CSInterviewQuestions implements InterviewQuestion {

    @Override
    public void execute() {
        System.out.println("CS questions without the need to modify InterviewQuestionProcessor.");
    }
    
}
