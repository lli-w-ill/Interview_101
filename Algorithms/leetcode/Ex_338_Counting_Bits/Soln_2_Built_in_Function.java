package Algorithms.leetcode.Ex_338_Counting_Bits;

class Solution_2 {
    public int[] countBits(int num) {
        int[] res = new int[num+1];
        for (int i = 0; i <= num; i++) {
            res[i] = Integer.bitCount(i);
        }
        return res;
    }
}
