#include <vector>

using std::vector;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_3 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        // 定义另一个临时指针，避免直接移动head，因为可能会导致调用isPalindrome函数前后原生链表发生变化
        ListNode *cur = head;
        // 步骤1: 将链表中的节点中的值逐个放在数组里
        while (cur != nullptr) {
            vals.push_back(cur->val);
            cur = cur->next;
        }
        // 步骤2: 利用双指针／双下标法判断数组中的值是否回文
        int front = 0;
        int back = vals.size() - 1;
        while (front < back) {
            if (vals[front] != vals[back]) {
                return false;
            }
            front += 1;
            back -= 1;
        }
        return true;
    }
};

// 参考题解：https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode-solution/
