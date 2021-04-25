class Solution_5 {
public:
    int mySqrt(int x) {
        long a = x;     // 用 long 型防止 a * a 溢出
        while (a * a - x > 0) { 
            // 牛顿迭代公式：x_(n+1) = ( x_(n) + a/x_(n) ) / 2
            a = (a + x / a) / 2;
        }
        return a;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
