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
    ListNode* deleteDuplicates(ListNode* head) {
        // 将 head 移动到第一个不重复的 node
        while (head && head->next && head->val == head->next->val) {
            long valueToDelete = head->val;
            while (head && head->val == valueToDelete) {
                head = head->next;
            }
        }

        // 检查第一个不重复的节点
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *pre = nullptr;    // 指向上一个不重复节点
        ListNode *cur = head;       // 指向下一个不重复节点
        long valueToDelete;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                // 当前值与下一个节点的值相同
                // 设置要删除的值，然后删除当前和其后连续的所有等于该值的节点
                valueToDelete = cur->val;
            }
            if (cur->val == valueToDelete) {
                ListNode *next = cur->next; // 提前记录下一个节点
                if (pre) {
                    pre->next = next;
                }
                cur->next = nullptr;
                delete cur;
                cur = next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};

// 参考之前账号提交记录
