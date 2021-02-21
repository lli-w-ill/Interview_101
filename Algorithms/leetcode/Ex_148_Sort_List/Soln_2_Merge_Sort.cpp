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
    ListNode* sortList(ListNode* head) {
        // 特判
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 为排序后的链表做一个伪头节点
        ListNode newHead(-1);
        ListNode *newIt = &newHead;
        
        // 首先将当前链表在中间分为两半（详见Ex876. 链表的中间结点）
        ListNode *prevSlow = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 此时 slow 正在指向链表最中间的节点，如果链表长度为偶数， slow 指向中间两个节点的第二个节点，所有 prevSlow 指向中间节点的第一个节点
        // 所以 slow 可以作为右边一半链的头节点，head 作为左边一半链的头节点
        // 切断两条链（这里不用判断 prevSlow 不为空，因为如果只有一个节点，特判会直接返回；从两个及两个节点以上的链表，prevSlow就不为空了）
        prevSlow->next = nullptr;

        // 分别将两个半条链排序
        ListNode *sl1 = sortList(head);
        ListNode *sl2 = sortList(slow);

        // 合并两条排序后的链
        return merge(sl1, sl2);
    }

private:
    ListNode *merge(ListNode *sl1, ListNode *sl2) {
        ListNode dummyHead (-1);  // 作为合并之后链的伪头节点
        ListNode *itHead = &dummyHead;

        while (sl1 != nullptr && sl2 != nullptr) {
            if (sl1->val <= sl2->val) {
                // 将sl1接在「结果链」的末尾，sl1前进一步
                itHead->next = sl1;
                sl1 = sl1->next;    
            } else {
                // 将sl1接在「结果链」的末尾，sl1前进一步
                itHead->next = sl2;
                sl2 = sl2->next;
            }
            itHead = itHead->next;
        }
        // 将其中还没遍历完的链表全部接在「结果链」的末尾
        if (sl1 != nullptr) {
            itHead->next = sl1;
        } else if (sl2 != nullptr) {
            itHead->next = sl2;
        }
        return dummyHead.next;
    }
};

// 由排序时间是O(nlogn)，所以应该想到的是归并排序／堆排序（复杂度表见Algorithms/classic/sort），而堆排序是一个树形结构，而这道题需要的是链状结构，所以应该选用的是归并排序

