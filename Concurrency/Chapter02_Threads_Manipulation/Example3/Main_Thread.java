package Concurrency.Chapter02_Threads_Manipulation.Example3;

public class Main_Thread {
    
    public static void main(String[] args) {

        String name = Thread.currentThread().getName();
        System.out.println(name);

    }

}
