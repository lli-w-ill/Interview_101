class Solution_5 {
public:
    bool isPowerOfThree(int n) {
        // int 范围内 3的最大次幂是 3^19 = 1162261467
        return n > 0 && 1162261467 % n == 0;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
