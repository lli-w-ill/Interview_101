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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddHead = head;
        if (oddHead == nullptr) {
            // 空链表
            return oddHead;
        }
        ListNode *evenHead = head->next;
        if (evenHead == nullptr) {
            // 链表只有一个结点
            return oddHead;
        }

        ListNode *oddIt = oddHead;
        ListNode *evenIt = evenHead;
        while (oddIt && evenIt) {
            // 更新奇数节点的下一个节点
            oddIt->next = evenIt->next;

            // 更新偶数节点的下一个节点
            if (evenIt->next == nullptr) {
                break;
            }
            evenIt->next = evenIt->next->next;

            // 更新 oddIt, evenIt
            oddIt = oddIt->next;
            evenIt = evenIt->next;
        }

        // 连接奇数链和偶数链
        oddIt->next = evenHead;

        return oddHead;
    }
};

// 建议在纸上花一遍当原链表长度分别是奇数和偶数是 oddIt, evenIt 的更新情况
// 这里的更新策略是：
// oddIt 每次更新到 evenIt 所指的下一个节点
// evenIt 每次更新到 evenIt 所指的下两个节点（所以需要判断 evenIt 的下一个节点是否存在）
// 最后退出 while 循环时 oddIt 一定指向奇数链的最后一个节点，然后将奇偶链表相连即可
