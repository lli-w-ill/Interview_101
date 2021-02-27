package Algorithms.leetcode.Ex_0621_Task_Scheduler;

import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Err_1 {
    class Node {
        int remain; // 还剩余的个数
        char task;   // 冷却时间

        public Node(int r, char t) {
            remain = r;
            task = t;
        }
    }

    public int leastInterval(char[] tasks, int n) {
        PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if (o1.remain < o2.remain) {
                    // 先干剩余数量多的任务
                    return 1;
                } else if (o1.remain == o2.remain) {
                    return 0;
                } else {
                    return -1;
                }
            }
        });

        // 冷却时间表
        Map<Character, Integer> cooldown = new HashMap<Character, Integer>();
        // 将所有任务加入到pq
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (char t : tasks) {
            if (map.containsKey(t)) {
                map.put(t, map.get(t) + 1);
            } else {
                map.put(t, 1);
            }
            // 初始化冷却时间
            if (cooldown.containsKey(t)) {
                continue;
            } else {
                cooldown.put(t, 0);
            }
        }
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            Node task = new Node(entry.getValue(), entry.getKey());
            pq.add(task);
        }

        // 每次执行第一个冷却时间为0的队头元素
        int res = 0;
        while (!pq.isEmpty()) {
            // 保存所有队头元素，但是因为冷却时间无法在本轮执行的任务，在while结尾会重新将这些任务加回到pq中
            List<Node> waitlist = new ArrayList<Node>();

            // 找到第一个冷却时间为0的任务
            while (!pq.isEmpty()) {
                Node first = pq.poll();
                if (cooldown.get(first.task) == 0) {
                    first.remain -= 1;
                    if (first.remain == 0) {
                        // first任务完成，删除cooldown中的记录
                        cooldown.remove(first.task);
                    } else {
                        cooldown.put(first.task, n + 1);   // 因为循环会递减一次cooldown，抵消掉+1
                        pq.add(first);
                    }
                    break;
                } else {
                    waitlist.add(first);
                }
            }

            // 递减所有任务的cooldown时间
            for (Map.Entry<Character, Integer> entry : map.entrySet()) {
                if (map.get(entry.getKey()) > 0) {
                    map.put(entry.getKey(), map.get(entry.getKey()) - 1) ;
                }
            }
            // 将waitlist中所有任务重新加到pq中
            for (Node node : waitlist) {
                pq.add(node);
            }
            res += 1;
        }
        return res;
    }
}

// 错因：陷入无限循环
