package Concurrency.Chapter05_Java_Concurrent_Collections.Example6;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

class FirstWorker implements Runnable {

    private ConcurrentMap<String, Integer> map;

    public FirstWorker(ConcurrentMap<String, Integer> map) {
        this.map = map;
    }

    @Override
    public void run() {
        try {
            map.put("H", 1);
            map.put("E", 2);
            Thread.sleep(1000);
            map.put("L", 3);
            map.put("L", 4);
            Thread.sleep(1000);
            map.put("O", 5);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}

class SecondWorker implements Runnable {

    private ConcurrentMap<String, Integer> map;

    public SecondWorker(ConcurrentMap<String, Integer> map) {
        this.map = map;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(1000);
            System.out.println(map.get("H"));
            System.out.println(map.get("E"));
            System.out.println(map.get("L"));
            Thread.sleep(1000);
            System.out.println(map.get("O"));
            System.out.println(map.get("C"));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}

public class Example6 {

    public static void main(String[] args) {

        ConcurrentMap<String, Integer> map = new ConcurrentHashMap<>();

        new Thread(new FirstWorker(map)).start();
        new Thread(new SecondWorker(map)).start();

        List<String> list = new ArrayList<>();
        List<String> syncList = Collections.synchronizedList(list); // faster than synchronized keyword

    }

}
