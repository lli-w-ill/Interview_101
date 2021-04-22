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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-1, head);
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *it = dummy->next; // iterator
        ListNode *preIt = nullptr;    // 指向 iterator 前的一个节点（用于当遇到 it->val < x 时修改原链表，跳过 it）
        // 初始化 it 为第一个小于 x 的节点, preIt 为 it 前一个节点
        while (it && it->val >= x) {
            preIt = it;
            it = it->next;
        }

        // 从 head 开始找到第一个大于等于 x 的节点（作为大于等于 x 节点所组成的链表的头节点
        ListNode *firstLarge = head;
        while (firstLarge && firstLarge->val < x) {
            firstLarge = firstLarge->next;
        }

        ListNode *resEnd = dummy;   // 总指向结果链表中的最后一个小于 x 的节点

        while (it) {
            if (it->val < x) {
                // 跳过 it
                if (preIt) {
                    preIt->next = it->next;
                }
                // 将 it 加入到 结果链表中的尾部
                resEnd->next = it;

                // 更新 resEnd, it（保持 preIt 不变）
                resEnd = resEnd->next;
                ListNode *next = it->next;
                it->next = nullptr;
                it = next;
            } else {
                preIt = it;
                it = it->next;
            }
        }
        
        // 将结果链最后一个节点和 大于等于x 的第一个节点连接在一起
        resEnd->next = firstLarge;

        return dummy->next;
    }
};

