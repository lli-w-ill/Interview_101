package Algorithms.leetcode.Ex_451_Sort_Characters_By_Frequency;

import java.util.Random;

class Solution {
    // 记录每个字符的出现频率
    private int[] freq;

    private static final Random RANDOM = new Random();

    public String frequencySort(String s) {
        // 转换为字符数组，避免chatAt需要检查下标有效性
        char[] charArray = s.toCharArray();
        freq = new int[128];
        for (char c : charArray) {
            freq[c] += 1;
        }
        int len = charArray.length;
        quickSort(charArray, 0, len - 1);
        return new String(charArray);
    }

    private void quickSort(char[] charArray, int left, int right) {
        if (left >= right) {
            return;
        }
        // 随机生成一个[left, right]之间的下标，并在charArray中与left下标交换值
        int randomIndex = left + RANDOM.nextInt(right - left + 1);
        swap(charArray, randomIndex, left);
        // 循环不变量：
        // charArray[left+1 ... lt] 字符的频率 > pivot 字符的频率
        // charArray[lt+1 ... i) 字符的频率 = pivot 字符的频率
        // charArray[gt ... right] 字符的频率 < pivot 字符的频率
        // [i, gt)是还没有扫过的下标
        int pivot = charArray[left];
        int lt = left; // 初始保证[left+1 ... lt]为空
        int gt = right + 1; // 初始保证[gt ... right]为空
        // 开始循环
        int i = left + 1;
        while (i < gt) {
            if (freq[charArray[i]] > freq[pivot]) {
                lt += 1;
                swap(charArray, i, lt);
                i += 1;
            } else if (charArray[i] == pivot) {
                i += 1;
            } else {
                gt -= 1;
                swap(charArray, i, gt);
            }
        }
        swap(charArray, left, lt);
        quickSort(charArray, left, lt - 1);
        quickSort(charArray, gt, right);
    }

    private void swap(char[] charArray, int i1, int i2) {
        char temp = charArray[i1];
        charArray[i1] = charArray[i2];
        charArray[i2] = temp;
    }
}

// 参考：https://leetcode-cn.com/problems/sort-colors/solution/kuai-su-pai-xu-partition-guo-cheng-she-ji-xun-huan/