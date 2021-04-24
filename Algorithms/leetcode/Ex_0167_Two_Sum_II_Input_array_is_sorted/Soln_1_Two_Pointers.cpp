#include <vector>

using std::vector;

class Solution_1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int l = 0;
        int r = size - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target) {
                r --;
            } else if (sum < target) {
                l ++;
            } else if (sum == target) {
                return vector<int> {l + 1, r + 1};
            }
        }
        return vector<int> {};
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394


