package DesignPatterns.Chapter02_Creational_Design_Patterns.P1_Singleton_Pattern.Version1_Eager_Version;

public class Example1 {
    
    public static void main(String[] args) {

        // new DatabaseConnector();   // cannot instantiate (private constructor)

        DatabaseConnector.getInstance().connect();
        DatabaseConnector.getInstance().disconnect();
        
    }

}
