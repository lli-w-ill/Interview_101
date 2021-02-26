package Algorithms.leetcode.Ex_461_Hamming_Distance;

class Solution_2 {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}

// 参考题解：https://leetcode-cn.com/problems/hamming-distance/solution/yi-ming-ju-chi-by-leetcode/
