package Algorithms.leetcode.Ex_4_Median_of_Two_Sorted_Arrays;

import java.util.List;
import java.util.ArrayList;

class Solution_1 {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        List<Integer> li = new ArrayList<Integer>();
        int i = 0;
        int j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] <= nums2[j]) {
                li.add(nums1[i]);
                i += 1;
            } else {
                li.add(nums2[j]);
                j += 1;
            }
        }
        // 把剩余的数字加入li
        while (i < nums1.length) {
            li.add(nums1[i]);
            i += 1;
        }
        while (j < nums2.length) {
            li.add(nums2[j]);
            j += 1;
        }

        if (li.size() == 0) {
            return 0.0;
        } else if (li.size() % 2 == 1) {
            return li.get(li.size() / 2);
        } else {
            return (li.get(li.size() / 2 - 1) + li.get(li.size() / 2)) / 2.0;
        }
    }
}
