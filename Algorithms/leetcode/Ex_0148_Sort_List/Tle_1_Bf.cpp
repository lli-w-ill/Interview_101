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

class Tle_1 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 为排序后的链表做一个伪头节点
        ListNode newHead(-1);
        ListNode *newIt = &newHead;
        
        int min;
        ListNode *prevMinNode;
        ListNode *minNode;
        while (head != nullptr) {
            // 初始最小节点为无序链表的头节点
            min = head->val;
            prevMinNode = nullptr;  // 记录最小节点的前一个节点
            minNode = head;
            // 在无序链表中找到最小的节点
            for (ListNode *it = head; it->next != nullptr; it = it->next) {
                if (it->next->val < min) {
                    min = it->next->val;
                    minNode = it->next;
                    prevMinNode = it;
                }
            }
            if (minNode == head) {
                // 最小的是头节点
                // 当最后为排序的链表中只剩下一个节点时，head最后会被置空，也就结束while循环
                head = head->next;
            } else {
                // 如果最小不是头节点，那么就从无序链表中删除最小节点
                removeNode(minNode, prevMinNode);
            }
            // 将头节点连接在排序好的链表末尾
            newIt->next = minNode;
            newIt = newIt->next;
        }
        return newHead.next;
    }

private:
    void removeNode(ListNode *node, ListNode *prev) {
        prev->next = node->next;
        node->next = nullptr;
    }
};

// 暴力破解法的时间复杂度：O(n^2)
// 超出时间限制
