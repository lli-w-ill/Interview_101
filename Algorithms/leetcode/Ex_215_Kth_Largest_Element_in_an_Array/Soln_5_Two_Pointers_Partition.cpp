#include <vector>
#include <algorithm>    // std::swap
#include <cstdlib>      // std::rand

using std::vector;
using std::swap;
using std::rand;

class Solution_5 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int target = size - k;

        int left = 0;
        int right = size - 1;
        while (true) {
            int index = partition(nums, left, right);
            if (index == target) {
                return nums[index];
            } else if (index > target) {
                // 排定的元素的最终位置大于我们要求的最终位置，则收缩右边界
                right = index - 1;
            } else if (index < target) {
                // 排定的元素的最终位置小于我们要求的最终位置，则收缩左边界
                left = index + 1;
            }
        }
    }

private:
    int partition(vector<int> &nums, int left, int right) {
        // 随机在 [left ... right) 中选择一个数值作为标定点 pivot
        // rand() % (right - left + 1)  =>  得到一个 [0, right - left] 的一个随机值
        // rand() % (right - left + 1) + left  =>  得到一个 [left, right] 的一个随机
        swap(nums[left], nums[rand() % (right - left + 1) + left]);

        int pivot = nums[left];
        while (left < right) {
            // ????
            while (left < right && nums[right] >= pivot) {
                right -= 1;
            }
            nums[left] = nums[right];
            // ???? 
            while (left < right && nums[left] < pivot) {
                left += 1;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

