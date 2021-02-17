#include <vector>

using std::vector;

class Solution_3 {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            return -1;
        } else if (len == 1) {
            return nums[0] == target ? 0 : -1;
        }
        return search(nums, target, 0, len - 1);
    }

private:
    int search(vector<int> &nums, int target, int left, int right) {
        if (right < left) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        // base cases
        if (nums[left] == target) {
            return left;
        } 
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[right] == target) {
            return right;
        }
        // 递归搜索
        if (nums[left] < nums[mid]) {
            // 说明nums[left ... mid]是升序的
            if (target > nums[left] && target < nums[mid]) {
                // 如果target在这个升序范围内，缩小递归范围
                return search(nums, target, left + 1, mid - 1);
            } else {
                // 如果target不在这个范围，则在nums[mid+1 ... right-1]里搜
                return search(nums, target, mid + 1, right - 1);
            }
        } else {
            // 说明nums[mid ... right]是升序的，且pivot in [left .. mid]
            if (target > nums[mid] && target < nums[right]) {
                // 如果target在这个升序范围内，缩小递归范围
                return search(nums, target, mid + 1, right - 1);
            } else {
                // 如果target不在这个范围，则在nums[left+1 ... mid-1]里搜
                return search(nums, target, left + 1, mid - 1);
            }
        }
    }
};
