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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        // 首先让 itorA 和 itorB 分别向前走到当前链表的末尾
        // 当 itorA，itorB 走到当前链表的末尾时，将 itorA 赋值为 headB，itorB 赋值为 headA
        // 此时如果有交点，itorA 和 itorB 一定相遇，否则 itorA 和 itorB 会在第二遍再次走到空
        ListNode *itorA = headA;
        ListNode *itorB = headB;
        int timeA = 0;  // 0 代表 itorA 还在 headA 上，1 代表 itorA 已经在 headB 上
        int timeB = 0;  // 0 代表 itorB 还在 headB 上，1 代表 itorB 已经在 headA 上
        while (timeA <= 1 && timeB <= 1) {
            if (itorA == nullptr) {
                itorA = headB;
                timeA += 1;
            }
            if (itorB == nullptr) {
                itorB = headA;
                timeB += 1;
            }
            if (itorA == itorB) {
                return itorA;
            }
            itorA = itorA->next;
            itorB = itorB->next;
        }
        return nullptr;
    }
};
