#include <iostream>
#include <vector>

using std::vector;
using std::swap;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 2)
        {
            return;
        }

        // 循环不变量：
        // nums[0...zero] = 0
        // nums(zero, i) = 1
        // nums(two, len-1) = 2
        // 注意这里与Soln_2中区间zero和two两点的区别
        // 循环停止条件：i == two + 1

        int zero = -1;     // 初始保证[0...zero]为空
        int two = len - 1; // 初始保证(two, len-1)为空
        int i = 0;
        while (i <= two)
        {
            if (nums[i] == 0)
            {
                zero += 1;
                swap(nums[zero], nums[i]);
                i += 1;
            }
            else if (nums[i] == 1)
            {
                i += 1;
            }
            else
            {
                swap(nums[i], nums[two]);
                two -= 1;
            }
        }
    }
};

// 参考：https://leetcode-cn.com/problems/sort-colors/solution/kuai-su-pai-xu-partition-guo-cheng-she-ji-xun-huan/
