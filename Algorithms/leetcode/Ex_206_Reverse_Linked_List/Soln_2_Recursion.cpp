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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 递归前 head 表示当前节点更为恰当
        // 得到当前节点之后（不包括当前节点）翻转后的头节点
        ListNode *reversedHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversedHead;
    }
};

// 建议在纸上画出来
// 3 --> 2 --> 1 --> 4 --> 5
// ^                       ^
// head                    reversedHead
//
// 3 <-- 2 --> 1 --> 4 --> 5
//       ^                 ^
//       head              reversedHead
//
// 3 <-- 2 <-- 1 --> 4 --> 5
//             ^           ^
//             head        reversedHead
//
// 3 <-- 2 <-- 1 <-- 4 --> 5
//                   ^     ^ 
//                   head  reversedHead
//
// 3 <-- 2 <-- 1 <-- 4 <-- 5
