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

class Solution_1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 首先将头节点设置为非 val 的第一个节点
        while (head && head->val == val) {
            head = head->next;
        }
        if (head == nullptr) {
            return head;
        }

        ListNode *pre = head;       // 总是指向 cur 的前一个节点
        ListNode *cur = head->next;
        
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};
