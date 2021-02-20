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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        // 为了让 slow 和 fast 不至于一上来指向同一个节点，先让它们各自走一步/两步
        ListNode *slow = head->next;;
        ListNode *fast = head->next->next;
        // 首先让slow, fast各自向前推进，直到第一次相遇或fast为空
        while (fast != nullptr && fast->next != nullptr & fast != slow) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 判断链表中是否存在环
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        // 如果slow与fast相遇，则重置fast到起点head，然后让fast以与slow相同的速度继续向前推进，第二次slow与fast相遇之时，就是环中的第一个节点
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
