package Algorithms.leetcode.Ex_128_Longest_Consecutive_Sequence;

import java.util.Set;
import java.util.HashSet;

class Solution_2 {
    public int longestConsecutive(int[] nums) {
        // 将所有数字 -> set
        Set<Integer> numSet = new HashSet<Integer>();
        for (int num : nums) {
            numSet.add(num);
        }
    
        int res = 0;
        for (int num : numSet) {
            if (numSet.contains(num - 1)) {
                // 如果num - 1存在于set中，说明之后一定会循环到num的前驱（即num-1），所以当循环到num-1时开始逐个计数时，一定会算上num
                // 所以直接跳过当前num即可
                continue;
            } else {
                // 如果num的前驱不在set中，说明这是一个新的开始，要从num开始开始计数，逐渐累加 -> 在set中查找 -> 直到累加到一个在set中查不到的值为止
                int curNum = num;
                int curLen = 1;
                while (numSet.contains(curNum + 1)) {
                    curNum += 1;
                    curLen += 1;
                }
                if (curLen > res) {
                    res = curLen;
                }
            }
        }
        return res;
    }
}

// 题解参考：https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode-solution/
// 时间复杂度：O(n)
// 空间复杂度：O(n)
