package DesignPatterns.Chapter06_Service_Locator_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {

        // firstly, create and cache database service in ServiceLocator, because it doesn't exist at all
        Service s = ServiceLocator.getService("database service");
        s.execute();

        // now, database service has existed, so just return
        s = ServiceLocator.getService("database service");
        s.execute();


        // firstly, create and cache messaging service in ServiceLocator
        s = ServiceLocator.getService("messaging service");
        s.execute();

    }

}
