package Concurrency.Chapter03_Inter_Thread_Communication.Example2;

public class Two_Independent_Synchonized {
    
    public static int counter1 = 0;
    public static int counter2 = 0;

    // because the class has a single intrinsic lock, this is why the methods increment1() and increment2() cannot be executed "at the same time" - time slicing algorithm
    // 最好使用 synchonized block instead of synchonized method
    public static /* synchronized */ void increment1() {
        // class-lvel locking
        // rule of thumb: we synchonized blocks that are 100% necessary
        synchronized(Two_Independent_Synchonized.class) {
            counter1++;
        }
        
    }

    public static /* synchronized */ void increment2() {
        synchronized(Two_Independent_Synchonized.class) {
            counter2++;
        }
    }

    public static void process() {

        Thread t1 = new Thread(new Runnable(){

            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    increment1();
                }
            }
            
        });

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
