#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_3 {
public:
    void deleteNode(ListNode* node) {
        // 将下一个node的值赋给当前，并删除下一个node
        ListNode *node2Delete = node->next;
        *node = *node->next;
        // 删除节点
        delete node2Delete;
    }
};
