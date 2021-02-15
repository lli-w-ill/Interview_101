package Algorithms.leetcode.Ex_347_Top_K_Frequent_Elements;

import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Comparator;

class Solution_2 {
    public int[] topKFrequent(int[] nums, int k) {
        // 计算每个数字出现的频率
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        // 遍历map，维护一个size=k的最小堆，且堆顶数字的频率是堆中所有数字中最低的数字
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return freq.get(a) - freq.get(b); // 通过比较数字的频率，来判断大小
            }
        });
        for (Integer key : freq.keySet()) {
            if (pq.size() < k) {
                // 如果堆中元素还不足k，则直接进堆
                pq.add(key);
            } else {
                // 比较当前数字与堆顶数字的频率，如果当前数字的频率更大，则进堆，否则不进堆
                if (freq.get(key) > freq.get(pq.peek())) {
                    pq.remove(); // 移除堆顶数字
                    pq.add(key);
                }
            }
        }
        // 收集结果
        int[] res = new int[k];
        int index = 0;
        while (!pq.isEmpty()) {
            res[index++] = pq.remove();
        }
        return res;
    }
}

// 参考：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/leetcode-di-347-hao-wen-ti-qian-k-ge-gao-pin-yuan-/
