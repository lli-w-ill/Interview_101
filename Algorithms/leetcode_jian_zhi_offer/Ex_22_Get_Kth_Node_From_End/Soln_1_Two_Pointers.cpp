#include <iostream>

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_1 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p = head;
        ListNode *q = head;
        // 先让 p 往前走 k 步
        while (k--) {
            p = p->next;
        }
        // 之后 p 和 q 同时向前推进，直到 p 为空时，q 所指就是倒数第 k 个节点
        while (p) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};

// 题解参考（强烈推荐）：https://leetcode-cn.com/problems/linked-list-cycle/solution/yi-wen-gao-ding-chang-jian-de-lian-biao-wen-ti-h-2/
// 这道题和「Ex19: 删除链表的倒数第 N 个结点」有共同之处
