#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution_2 {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            return -1;
        } else if (len == 1) {
            return nums[0] == target ? 0 : -1;
        }
        // 首先判断nums是否在两端旋转了（因为如果pivot在两端 0 或者 len-1，nums中数字还是单调递增的）
        if (nums[0] > nums[len-1]) {
            // 说明pivot在中间，即 pivot in [1 ... len - 2]
            // 首先先找到pivot的下标，即nums[pivot] > nums[pivot+1]
            int pivotIdx = search4Pivot(nums, 0, len - 1);
            cout << pivotIdx << endl;
            // 然后判断target是在哪段 [0 ... pivotIdx] 还是 [pivotIdx + 1, len - 1]
            if (target >= nums[0] && target <= nums[pivotIdx]) {
                return binarySearch(nums, target, 0, pivotIdx);
            } else if (target < nums[0] && target >= nums[pivotIdx + 1]) {
                return binarySearch(nums, target, pivotIdx + 1, len - 1);
            } else {
                return -1;
            }
        } else {
            // 说明pivot在两端，那么直接进行二分查找即可
            return binarySearch(nums, target, 0, len - 1);
        }
    }

private:
    int search4Pivot(vector<int> &nums, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid+1]) {
                return mid;
            } else if (nums[mid] > nums[right]) {
                // 说明pivot in [mid ... right]
                left = mid;
            } else if (nums[mid] < nums[right]) {
                // 说明pivot in [left, mid-1]
                right = mid;
            }
        }
        return -1;
    }

    int binarySearch(vector<int> &nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return -1;
    }
};

// 注：看完题解后，这道题没有必要去找pivot的位置，我真是猪。。。参照Soln_4解法，很经典
