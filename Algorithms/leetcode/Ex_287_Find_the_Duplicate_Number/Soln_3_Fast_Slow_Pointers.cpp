#include <vector>

using std::vector;

class Solution_3 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        // 注意这里第一次slow==fast不一定是相遇于重复元素，也有可能二者此时指向同一的元素

        fast = nums[0]; // 等同于Ex142中将fast置回head
        // 然后 fast 与 slow 以相同速度向前，再相遇时就是指向重复元素
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// 参考之前提交的解法
// 这道题与 Ex142: Linked List Cycle II 的想法有异曲同工之处

