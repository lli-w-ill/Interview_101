package DesignPatterns.Chapter02_Creational_Design_Patterns.P1_Singleton_Pattern.Version4_Enum;

public class Example1 {
    
    public static void main(String[] args) {
        
        Database.INSTANCE.connect();
        Database.INSTANCE.disconnect();

        // 检查两个 instances 是否来自相同地址
        Database o1 = Database.INSTANCE;
        Database o2 = Database.INSTANCE;
        if (o1 == o2) {
            System.out.println("The objects are the same...");
        } else {
            System.out.println("The objects are different...");
        }
    }

}
