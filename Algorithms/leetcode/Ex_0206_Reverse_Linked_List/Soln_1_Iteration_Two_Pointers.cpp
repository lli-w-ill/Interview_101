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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pre = head;
        ListNode *cur = head->next;
        pre->next = nullptr;   // 对头节点next置空，变为尾节点
        while (cur != nullptr) {
            // 首先保存 cur 的下一个节点
            ListNode *curNext = cur->next;
            cur->next = pre;
            // 更新 pre, cur
            pre = cur;
            cur = curNext;
        }
        // 最终 pre 指向原链表的尾节点，即翻转链表的头节点
        return pre;
    }
};