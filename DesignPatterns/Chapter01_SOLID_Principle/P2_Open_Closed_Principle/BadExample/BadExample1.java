package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.BadExample;

/**
 * Why this is bad ?
 * Because if we need to create another interview question topic, we have to create a distinct class and then add an if statement in InterviewQuestionProcessor.
 * 
 */
public class BadExample1 {
    
    public static void main(String[] args) {

        InterviewQuestionProcessor.process(new AlgorithmInterviewQuestions());

        InterviewQuestionProcessor.process(new AIInterviewQuestions());

        InterviewQuestionProcessor.process(new FinanceInterviewQuestions());
        
    }

}
