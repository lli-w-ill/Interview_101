package Algorithms.leetcode.Ex_0347_Top_K_Frequent_Elements;

import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution_3 {
    @SuppressWarnings("unchecked") // 忽略类型检查导致的warnings
    public int[] topKFrequent(int[] nums, int k) {
        // 计算每个数字出现的频率
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        // 桶排序：以频率（freq中的value）作为数组下标，对频率不同的数字，存入对应的数组下标
        List<Integer>[] list = new List[nums.length + 1];
        for (int key : freq.keySet()) {
            // 获得该数字的频率，作为下标
            int i = freq.get(key);
            if (list[i] == null) {
                // 如果当前频率的桶还未被初始化，则先初始化
                list[i] = new ArrayList<Integer>();
            }
            // 将当前数字加入到对应频率的桶中
            list[i].add(key);
        }
        // 倒着扫描所有桶（即从频率最大的桶开始），依次加入桶中的数字，直到结果集中的数字达到k个为止
        List<Integer> res = new ArrayList<Integer>();
        for (int i = list.length - 1; i >= 0 && res.size() < k; i--) {
            if (list[i] == null) {
                // 当前桶为空，尝试前一个桶（即频率更小的桶）
                continue;
            }
            // 由于题目说，结果是唯一的，所以不需要逐个数字加入，每次判断数字是否达到k个，一次性全部加入res就好
            res.addAll(list[i]);
        }
        // List<Integer> 转换成 int[]
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}

// 参考：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/leetcode-di-347-hao-wen-ti-qian-k-ge-gao-pin-yuan-/
// List<Integer> -> int[]:
// https://stackoverflow.com/questions/960431/how-to-convert-listinteger-to-int-in-java
