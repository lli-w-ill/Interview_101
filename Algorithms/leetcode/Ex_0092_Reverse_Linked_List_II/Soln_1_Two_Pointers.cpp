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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *preLeft = nullptr;
        ListNode *slow = head;
        ListNode *fast = head->next;
        int cnt = 1;

        // 首先将 slow 移动到第 left 个 node
        while (cnt < left) {
            preLeft = slow;
            slow = slow->next;
            fast = fast->next;
            cnt ++;
        }

        // 记住当前的 slow 是 第left个node
        ListNode *leftNode = slow;
        
        // 翻转 从 第left+1 到 第right 的next指针
        // 1 -> 2 -> 3 -> 4 -> 5 -> x
        // => 
        // 1 -> 2 <- 3 <- 4    5 -> x
        // ^    ^         ^    ^ 
        // preLeft             postRight
        //      leftNode  rightNode
        ListNode *nextFast;
        while (cnt < right) {
            nextFast = fast->next;
            fast->next = slow;
            
            slow = fast;
            fast = nextFast;
            cnt ++;
        }
        ListNode *postRight = fast;    
        ListNode *rightNode = slow;

        // 将 2 的 next 连到 5，1 的 next 连到 4
        leftNode->next = postRight;
        if (preLeft != nullptr) {
            preLeft->next = slow;
        }

        if (left == 1) {
            // 说明从第一个 node 就开始反转了，所以新的头节点是 rightNode
            return rightNode;
        } else {
            // 头节点没有变
            return head;
        }
    }
};
