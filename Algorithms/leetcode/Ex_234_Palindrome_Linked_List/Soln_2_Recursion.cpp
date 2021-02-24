#include <iostream>

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

class Solution_2 {
public:
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }

private:
    // 永远是从前往后
    ListNode *temp;

    // p永远是从后往前
    bool check(ListNode *p) {
        if (p == nullptr) {
            return true;
        }
        bool isPal = check(p->next) && (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};

// 参考以前写的解法，这个解法真的神！
// 建议在纸上模拟一下这个解法的过程。
// 但是因为递归栈的存在，这个解法的空间复杂度好像是O(n)
