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
    ListNode* rotateRight(ListNode* head, int k) {
        // 特判
        if (head == nullptr) {
            return head;
        }

        // 首先计算当前链表的长度，并排除轮回翻转，计算出一轮回内需要翻转的次数
        k = k % countLength(head);
        if (k == 0) {
            return head;
        }

        // 找到倒数第 k+1 个节点
        ListNode *lastK1 = getKthFromEnd(head, k+1);

        // lastK1 是旋转后的尾节点，lastK1 下一个节点是旋转后的头节点
        ListNode *newHead = lastK1->next;
        lastK1->next = nullptr;

        // 找到 newHead 的最后一个节点并与 head 连接
        ListNode *tail = newHead;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }

private:
    int countLength(ListNode *head) {
        int length = 0;
        ListNode *tail = head;
        while (tail != nullptr) {
            tail = tail->next;
            length ++;
        }
        return length;
    }

    ListNode* getKthFromEnd(ListNode *head, int k) {
        ListNode *slow = head;
        ListNode *fast = head;
        // fast 先走 k 步
        while (k--) {
            fast = fast->next;
        }
        // slow, fast 同时向前
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

// 找到链表中倒数第k个节点，参考剑指 Offer 22.：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
// 和剑指 Offer 22. 题解（强烈推荐）：https://leetcode-cn.com/problems/linked-list-cycle/solution/yi-wen-gao-ding-chang-jian-de-lian-biao-wen-ti-h-2/
