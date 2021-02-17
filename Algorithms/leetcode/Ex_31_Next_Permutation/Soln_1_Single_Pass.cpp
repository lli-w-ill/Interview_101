#include <vector>

using std::vector;

class Solution_1 {
public:
    void nextPermutation(vector<int>& nums) {
        // 思路：
        // nextPermutation实际上就是：
        // 第一步：找到一组相邻的升序pair (i, i+1 s.t. nums[i] < nums[i+1])
        // 第二步：从[i+1 ... len) 找到一个当且仅当大于nums[i]的数，并与nums[i]交换
        // 第三步：逆转[i+1 ... len)

        int len = nums.size();
        // 第一步：从后往前，找到第一个连续的两个数nums[i], nums[i+1]，且nums[i] < nums[i+1]
        // 1 2 3 4 5 9 8 7 6
        //               ^ ^
        //             ^ ^
        //           ^ ^
        //         ^ ^
        //         i i+1
        int i = len - 2;    // 注意：i也要从后往前找
        while (i >= 0 && nums[i] >= nums[i+1]) {
            i -= 1;
        }
        if (i >= 0) {
            // 说明找到了两个数
            // 从后往前，找到一个刚刚好大于nums[i]的数
            // 1 2 3 4 5 9 8 7 6
            //         ^       ^
            //         i       j
            int j = len - 1;
            while (j > i && nums[j] <= nums[i]) {
                j -= 1;
            }
            //         -       - swap
            // 1 2 3 4 6 9 8 7 5
            //         ^       ^
            //         i       j
            swap(nums, i, j);
            //           ------- reverse
            // 1 2 3 4 6 5 7 8 9
            //         ^       ^
            //         i       j
            reverse(nums, i + 1, len - 1);
        } else {
            // 如果没有找到两个数，说明整个数组已经是逆序的了，直接再逆序返回升序的数组
            reverse(nums, 0, len - 1);
        }
    }

private:
    // 逆转nums[start ... end] (两头闭区间)
    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start += 1;
            end -= 1;
        }
    }

    void swap(vector<int> &nums, int idx1, int idx2) {
        int len = nums.size();
        if (idx1 >= 0 && idx1 < len && idx2 >= 0 && idx2 < len) {
            int temp = nums[idx1];
            nums[idx1] = nums[idx2];
            nums[idx2] = temp;
        }
    }
};


// 动画参考：https://leetcode.com/problems/next-permutation/solution/