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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 创建一个伪头节点
        ListNode *newHead = new ListNode(-1);
        newHead->next = head->next; // 新的头节点一定是 head->next
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *oldSlow = nullptr;    // 用于链接上一个两两交换完的后的尾节点和下一个两两交换之后的头节点

        while (slow && fast) {
            slow->next = fast->next;
            fast->next = slow;
            // 连接上次两两交换的尾节点和这次两两交换后的头节点
            if (oldSlow != nullptr) {
                oldSlow->next = fast;
            }

            // 记录上一个交换后的尾节点
            oldSlow = slow;

            // 更新 slow, fast
            slow = slow->next;
            if (slow == nullptr) {
                // 链表是偶数个节点，已两两交换所有节点
                break;
            }
            fast = slow->next;
        }

        return newHead->next;
    }
};

// 建议在纸上画一个偶数长度的例子和奇数长度的例子
// 例如： 1 -> 2 -> 3 -> 4  和  1 -> 2 -> 3
