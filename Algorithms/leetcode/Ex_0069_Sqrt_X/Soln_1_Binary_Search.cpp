class Solution_1 {
public:
    int mySqrt(int x) {
        if (x <= 0)
            return 0;

        int lower = 1;
        int upper = x;
        int res = 0;
        while (lower <= upper) {
            int mid = lower + (upper - lower) / 2;
            if (mid > x / mid) {    // 不要计算 mid * mid, 因为可能溢出
                upper = mid - 1;
            } else if (mid <= x / mid) {
                res = mid;
                lower = mid + 1;
            }
        }

        return res;
    }
};
