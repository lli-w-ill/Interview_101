package Concurrency.Chapter02_Threads_Manipulation.Example1;

class Runner11 implements Runnable {
    public void execute() {
        for (int i = 0; i < 10; i++) {
            System.out.println("Runner1: " + i);
        }
    }

    @Override
    public void run() {
        execute();
    }
}

class Runner22 implements Runnable {
    public void execute() {
        for (int i = 0; i < 10; i++) {
            System.out.println("Runner2: " + i);
        }
    }

    @Override
    public void run() {
        execute();
    }
}

public class Example2_implement_Runnable {
    
    public static void main(String[] args) {

        // IT IS NOT PARALLEL EXECUTION
        // THIS IS MULTI-THREADING
        Thread t1 = new Thread(new Runner11());
        Thread t2 = new Thread(new Runner22());

        // 对比 Example2_sequential 的结果可以发现两个线程交错执行并输出
        t1.start();
        t2.start();
        
    }

}
