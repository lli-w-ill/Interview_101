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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        do {
            if (fast == nullptr || fast->next == nullptr) {
                // 没有环路
                return nullptr;
            }
            // 由于上面已经做了判断，所以无需在方法开头判断链表是否是空或者只有一个节点
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        // 第一次 slow, fast 相遇后需要将其中一个指针重置回 head, 然后每次一步向前走
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // 第二次相遇即为链表头节点
        return slow;
    }
};


// 参考 cycle detection: https://en.wikipedia.org/wiki/Cycle_detection
// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
