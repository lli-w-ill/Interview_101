package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.GoodExample;

/**
 * Why this is good ?
 * Because if we need to create another interview question topic, we only nned to create a distinct class and no need to change InterviewQuestionProcessor.
 * 
 */
public class GoodExample1 {
    
    public static void main(String[] args) {

        InterviewQuestionProcessor.process(new AlgorithmInterviewQuestions());

        InterviewQuestionProcessor.process(new AIInterviewQuestions());

        InterviewQuestionProcessor.process(new FinanceInterviewQuestions());
     
        InterviewQuestionProcessor.process(new CSInterviewQuestions());
        
    }

}
