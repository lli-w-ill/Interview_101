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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }   

        // 定义伪头节点
        ListNode *dummySmaller = new ListNode(-1);  // 小于 x 的伪头节点
        ListNode *dummyEqualOrLarger = new ListNode(-1);    // 大于等于 x 的伪头节点
        
        // 定义当前两个伪头节点的最后一个节点
        ListNode *smaller = dummySmaller;
        ListNode *equalOrLarger = dummyEqualOrLarger;

        for (ListNode *it = head; it != nullptr; it = it->next) {
            if (it->val < x) {
                // 将 it 加入到 smaller 的后面，并更新 smaller
                smaller->next = it;
                smaller = smaller->next;
            } else if (it->val >= x) {
                // 将 it 加入到 equalOrLarger 的后面
                equalOrLarger->next = it;
                equalOrLarger = equalOrLarger->next;
            }
        }

        // 把 大于等于x的链表的伪节点 的 next 指针置空
        equalOrLarger->next = nullptr;
        
        // 连接 小于x的链表的伪节点 和 大于等于x的链表的头节点
        smaller->next = dummyEqualOrLarger->next;

        return dummySmaller->next;
    }
};

// 参考题解：https://leetcode-cn.com/problems/partition-list/solution/c-xu-ni-tou-zhen-hao-yong-by-qing-feng-f-li88/
