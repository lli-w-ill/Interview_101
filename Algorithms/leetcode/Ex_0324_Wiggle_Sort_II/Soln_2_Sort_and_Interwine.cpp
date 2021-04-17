#include <vector>
#include <cmath>

using std::vector;
using std::ceil;

class Solution_2 {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1) {
            return;
        }

        // 排序
        sort(nums.begin(), nums.end());

        // 计算中间位置
        int mid = ceil(size / 2.0);
        // 分割为数组 A 和数组 B
        // 数组 A: nums[0 ... mid]
        // 数组 B: nums[mid+1 ... size-1]
        vector<int> A (nums.begin(), nums.begin() + mid);
        vector<int> B (nums.begin() + mid, nums.end());

        // 输出数组 A, B
        // cout << "A: ";
        // for (const int &a : A) {
        //     cout << a << " ";
        // }
        // cout << endl;
        // cout << "B: ";
        // for (const int &b : B) {
        //     cout << b << " ";
        // }
        // cout << endl;

        // 翻转数组 A, B 让大数在前，这个操作是为了解决 A 结尾处的重复的数 r 与 B 开始处重复的数 r 在穿插过程中相邻的问题，详见参考题解
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());

        // 开始穿插
        vector<int> res;
        int indexA = 0;
        int indexB = 0;
        // 由于是在中间切的
        // 如果 nums 原长度是偶数，那么分为 A B 之后两数组同样长度，最后会在检查 indexA 时退出循环
        // 如果 nums 原长度是奇数，那么分为 A B 之后 A 会比 B 多一个，最后在检查 indexB 时退出循环
        while (indexA < A.size() || indexB < B.size()) {
            // 先插入 A 中的数
            res.push_back(A[indexA]);
            indexA ++;

            // 插入 B 中的数时需要检查一下 indexB 是否已经越界了，如果越界了，说明原 nums 长度为奇数，直接退出即可
            if (indexB >= B.size()) {
                break;
            }

            // 插入 B 的数
            res.push_back(B[indexB]);
            indexB ++;
        }

        // 将结果集赋给 nums
        nums = res;

    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
// 设 N = nums.size()
// 时间复杂度：O(NlogN)
// 空间复杂度：O(N)
