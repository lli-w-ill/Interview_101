class Solution_3 {
public:
    bool isPowerOfThree(int n) {
        if (n > 0 && 1162261467 % n == 0) {
            return true;
        } else {
            return false;
        }
    }
};

// 参考题解下 @好想喝羊肉汤啊 的解法：https://leetcode-cn.com/problems/power-of-three/solution/mei-ju-ji-ke-by-scut_dell/
