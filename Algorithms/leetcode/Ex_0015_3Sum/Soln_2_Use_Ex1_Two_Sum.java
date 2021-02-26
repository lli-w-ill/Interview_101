package Algorithms.leetcode.Ex_0015_3Sum;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution_2 {
    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (len == 0) {
            return res;
        }
        Arrays.sort(nums);
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                // 去重，保证第一个值永远是所有相同数字在nums中最后一次出现的那个数
                continue;
            }
            int remain = 0 - nums[i];
            res.addAll(twoSum(nums, i + 1, len - 1, remain, nums[i]));
        }
        return res;
    }

    private List<List<Integer>> twoSum(int[] nums, int left, int right, int remain, int firstNum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        while (left < right) {
            int ssum = nums[left] + nums[right];
            if (ssum == remain) {
                // 找到一个二元组，其和为remain
                res.add(new ArrayList<Integer>(Arrays.asList(firstNum, nums[left], nums[right])));
                // 将left移动到下一个不同数字的下标
                while (left < right && nums[left] == nums[left + 1]) {
                    left += 1;
                }
                // 此时left指向最后一个相同数字的下标，再加一，指向下一个不同的数字
                left += 1;
                // 同理，将right移动到前一个不同数字的下标
                while (right > left && nums[right] == nums[right - 1]) {
                    right -= 1;
                }
                right -= 1;
            } else if (ssum > remain) {
                right -= 1;
            } else {
                left += 1;
            }
        }
        return res;
    }
}
