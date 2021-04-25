class Solution_4 {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        int l = 1;
        int r = x;
        int mid;
        int sqrt;
        
        // 这里二分法采用的都是「左闭右闭」原则
        while (l <= r) {
            // cout << l << " " << r << endl;
            mid = l + (r - l) / 2;
            sqrt = x / mid;     // 这里用除法避免溢出
            if (mid == sqrt) {
                return mid;
            } else if (mid > sqrt) {
                // 由于 sqrt = x / mid，所以说明 mid > x / mid => mid * mid > x
                // 左移右边界
                r = mid - 1;
            } else if (mid < sqrt) {
                // mid < x / mid => mid * mid < x
                // 右移左边界
                l = mid + 1;
            }
        }

        return r;   // 返回 l 不可以，原因是什么呢？
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
