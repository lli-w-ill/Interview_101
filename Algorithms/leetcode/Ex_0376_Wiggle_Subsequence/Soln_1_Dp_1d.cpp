#include <vector>

using std::vector;
using std::max;

class Solution_1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) {
            return 0;
        }

        // up[i] 代表 nums[0 ... i] 中子序列后两个数为升序的最长摆动序列长度
        // down[i] 代表 nums[0 ... i] 中子序列后两个数为降序的最长摆动序列长度
        // 初始化为 1 是因为每一个数都自构成长度为 1 的摆动序列
        vector<int> up (size, 1);
        vector<int> down (size, 1);

        // 开始填表
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if (nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            } else {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }

        return max(up[size-1], down[size-1]);
    }
};

// 参考题解（非常推荐，图解很清楚）：https://leetcode-cn.com/problems/wiggle-subsequence/solution/tan-xin-si-lu-qing-xi-er-zheng-que-de-ti-jie-by-lg/
// 题解中图解的疑问：
// 当平着复制时，应不应该更新最后一位呢？题解中的例子似乎没什么问题，但是如果例子是 [1, 5, 2, 3, 6, 4, 8, 7, 9]，中间这段 [2, 3, 6] 应不应该更新插图中 up, down 括号内的最后一位数字呢？
 