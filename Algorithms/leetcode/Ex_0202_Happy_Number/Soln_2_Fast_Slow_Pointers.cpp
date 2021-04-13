class Solution_2 {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(bitSquareSum(fast));
        } while (slow != fast);

        return slow == 1;
    }

private:
    int bitSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int bit = n % 10;
            sum += bit * bit;
            n /= 10;
        }
        return sum;
    }
};

// 参考题解：https://leetcode-cn.com/problems/happy-number/solution/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/
// 记住：凡是和找循环有关的题，可以往“快慢指针”思路上想
// 这道题并不建议使用 set 或者递归，因为循环中的数可能会很多，导致内存不足或栈溢出
