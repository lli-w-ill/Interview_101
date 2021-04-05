class Solution_2 {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;

        int left = 1;
        int right = x;
        while (left < right) {
            // 为什么 +1: 
            // 因为当区间 [left, ... right] 内只有两个数时，如果 mid 取下整，会陷入死循环 (手画 x=9)
            // +1 是为了取 mid 时向上取整
            // 如果向下取整(left=1,right=4)：mid = 1 + (4 - 1) / 2 = 1 + 3/2 = 2
            // 如果向上取整(left=1,right=4)：mid = 1 + (4 - 1 + 1) / 2 = 1 + 4/2 = 3
            int mid = left + (right - left + 1) / 2;
        
            if (mid > x / mid) {
                // 根号 x 一定不存在于 [mid ... x]
                // 根号 x 一定在 [1 ... mid-1] 中
                right = mid - 1;
            } else if (mid <= x / mid) {
                // 根号 x 一定在 [mid ... right] 中
                left = mid;
            }
        }

        return left;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/

