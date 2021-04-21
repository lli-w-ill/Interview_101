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
    ListNode* rotateRight(ListNode* head, int k) {
        // 特判
        if (head == nullptr) {
            return head;
        }

        // 首先计算当前链表的长度
        int length = 1;
        ListNode *tail = head;
        while (tail->next) {
            length ++;
            tail = tail->next;
        }
        // 将原链表首尾相连
        tail->next = head;
        // 排除轮回旋转
        k = k % length;

        // 找到新的头节点，即倒数第 k 个节点（或正数第 length-k+1 个节点）
        // 这里采用的是找正数节点，Soln_1 中采用的是找倒数节点
        for (int i = k; i < length; i++) {
            tail = tail->next;
        }
        ListNode *newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }

};

// 参考之前账号提交记录

