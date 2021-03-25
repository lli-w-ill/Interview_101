package DesignPatterns.Chapter02_Creational_Design_Patterns.P1_Singleton_Pattern.Version3_Lazy_Version_with_Sync;

public class Example1 {
    
    public static void main(String[] args) {

        // new DatabaseConnector();   // cannot instantiate (private constructor)

        DatabaseConnector.getInstance().connect();
        DatabaseConnector.getInstance().disconnect();

        // 检查两个 instances 是否来自相同地址
        DatabaseConnector o1 = DatabaseConnector.getInstance();
        DatabaseConnector o2 = DatabaseConnector.getInstance();
        if (o1 == o2) {
            System.out.println("The objects are the same...");
        } else {
            System.out.println("The objects are different...");
        }
    }

}
