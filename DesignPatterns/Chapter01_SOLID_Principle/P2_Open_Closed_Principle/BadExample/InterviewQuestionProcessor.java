package DesignPatterns.Chapter01_SOLID_Principle.P2_Open_Closed_Principle.BadExample;

public class InterviewQuestionProcessor {
    
    public static void process(InterviewQuestion question) {
        
        if (question instanceof AlgorithmInterviewQuestions) {
            AlgorithmInterviewQuestions algorithms = (AlgorithmInterviewQuestions) question;
            algorithms.executeAlgorithms();
        } else if (question instanceof AIInterviewQuestions) {
            AIInterviewQuestions ai = (AIInterviewQuestions) question;
            ai.executeAI();
        } else if (question instanceof FinanceInterviewQuestions) {
            FinanceInterviewQuestions finance = (FinanceInterviewQuestions) question;
            finance.executeFinance();
        }
    }

}
