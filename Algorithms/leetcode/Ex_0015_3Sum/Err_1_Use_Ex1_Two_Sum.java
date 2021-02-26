package Algorithms.leetcode.Ex_0015_3Sum;

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;

class Err_1 {
    Map<Integer, HashSet<Integer>> map = new HashMap<Integer, HashSet<Integer>>();

    public List<List<Integer>> threeSum(int[] nums) {
        // 初始化map
        // key: nums中的数字
        // value: nums中的数字对应的下标
        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], new HashSet<Integer>());
            }
            map.get(nums[i]).add(i);
        }
        // 记录每个数字是否已经使用过，true表示正在使用(unavailable)，false表示没有被使用(available)
        boolean[] availability = new boolean[nums.length];
        Arrays.fill(availability, true);
        // 每个数字作为第一个数，然后调用twoSum，查找nums中是否有其他两个数字的和是 0-#第一个数
        int len = nums.length;
        Set<List<Integer>> resSet = new HashSet<List<Integer>>();
        for (int i = 0; i < len; i++) {
            availability[i] = false; // nums[i] 用作第一个数
            int[] ts = twoSum(nums, 0 - nums[i], availability, i + 1); // 在 nums[i+1 ... END] 中找两个数，其和为0-nums[i]
            if (ts.length == 2) {
                ArrayList<Integer> temp = new ArrayList<Integer>(Arrays.asList(nums[i], ts[0], ts[1]));
                Collections.sort(temp);
                resSet.add(temp);
            }
            availability[i] = true; // 恢复可用性
        }
        return new ArrayList<List<Integer>>(resSet);
    }

    private int[] twoSum(int[] nums, int target, boolean[] availability, int start) {
        for (int i = start; i < nums.length; i++) {
            // 寻找另一个值，与nums[i]的和等于target
            int anotherNum = target - nums[i];
            if (!map.containsKey(anotherNum)) {
                continue;
            }
            // 另一个值所对应的所有下标
            HashSet<Integer> anotherNumIndices = map.get(anotherNum);

            if (nums[i] == anotherNum) {
                // 如果 nums[i] 与 anotherNum 是相同的值，则需要保证 anotherNumIndices 中至少有两个下标是 available 的
                int availablePos = 0;
                for (int idx : anotherNumIndices) {
                    if (availability[idx] == true) {
                        availablePos += 1;
                    }
                    if (availablePos == 2) {
                        return new int[] { nums[i], target - nums[i] };
                    }
                }
            } else {
                // 如果 nums[i] 与 anotherNum 是不同的值，则需要保证 anotherNumIndices 中至少有一个下标是 available 的
                for (int idx : anotherNumIndices) {
                    if (availability[idx] == true) {
                        return new int[] { nums[i], target - nums[i] };
                    }
                }
            }
        }
        return new int[0];
    }
}

// 错误测试用例：[-1,0,1,2,-1,-4,-2,-3,3,0,4]
// 错误输出：[[-1,-1,2],[-2,-1,3],[-3,1,2],[-4,1,3],[-1,0,1],[-3,0,3],[-4,0,4]]
// 预期结果：[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
// 区别：少输出 [-3,-1,4], [-2,0,2]
// 错因：？？？
