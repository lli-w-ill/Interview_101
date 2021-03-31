package Concurrency.Chapter03_Inter_Thread_Communication.Example2;

public class Object_Level_Lock {
    
    public static int counter1 = 0;
    public static int counter2 = 0;

    // custom objects
    // lock1 is used to lock increment1()
    // lock2 is used to lock increment2()
    private static final Object lock1 = new Object();
    private static final Object lock2 = new Object();

    public static /* synchronized */ void increment1() {
        // object-level locking
        // rule of thumb: we synchonized blocks that are 100% necessary
        synchronized(lock1) {
            counter1++;
        }
        
    }

    public static /* synchronized */ void increment2() {
        synchronized(lock2) {
            counter2++;
        }
    }

    public static void process() {

        // both t1 and t2 don't use the intrinsic lock of the class
        // t1 is going to lock lock1
        Thread t1 = new Thread(new Runnable(){

            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    increment1();
                }
            }
            
        });

        // t2 is going to lock lock2
        Thread t2 = new Thread(new Runnable(){

            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    increment2();
                }
            }
            
        });

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        System.out.println("The counter1 is: " + counter1);
        System.out.println("The counter2 is: " + counter2);

    }

    public static void main(String[] args) {

        // slower issue:
        // 当 Thread t1 获得 intrinsic lock the class 时， Thread t2 不能执行 increment2() 方法；反之，当 Thread t2 获得intrinsic lock the class 时， Thread t1 不能执行 increment1() 方法
        process();

    }

}
