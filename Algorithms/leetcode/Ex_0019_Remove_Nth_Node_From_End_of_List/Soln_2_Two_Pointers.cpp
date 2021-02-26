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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        // 先让 p 向前走 n 步（题目说n <= sz，所以不必考虑n大于链表长度的问题，即while条件不需要考虑p=nullptr的情况）
        while (n--) {
            p = p->next;
        }
        // 此时 p 指向了第 k+1 个节点（这里解释为什么不让 p 指向第 n 个，因为当 p 指向第 n+1 个节点，此时 q 指向第 1 个节点，这时 p 与 q 之间的距离恰好是n，即 q 要往前走 n 步才能能追上 p。那么当 p 向前推进到空节点时，q 还需要再往前走 n 步才能为空，即 q 与 p 之间还有 n-1 个节点，所以此时 q 指向的的是倒数第 n 个节点）（一定配合题解参考中的插图看！）
        // 举例：
        // 1 2 3 4 5 6 7 8 9 null     (设 n = 5)
        // p
        // q
        // 
        // 让 p 先走了 n 步:
        // 1 2 3 4 5 6 7 8 9 null
        // q         p
        // 
        // 依次往前推进
        // 1 2 3 4 5 6 7 8 9 null
        //   q ^ ^ ^   p ^ ^  ^
        //     q | |     p |  |
        //       q |       p  |
        //         q          p
        // 注意现在 q 和 p之间还有n-1 个节点，q还需要往前走n步才能追上p
        //
        // 让 p 和 q 同时向前推进，并记录 q 前一个节点
        ListNode *prev_q = nullptr;
        while (p != nullptr) {
            p = p->next;
            prev_q = q;
            q = q->next;
        }
        // 删除节点 q
        if (q == head) {
            // 删除的是头节点
            return head->next;
        } else {
            prev_q->next = q->next;
        }
        return head;
    }
};

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/linked-list-cycle/solution/yi-wen-gao-ding-chang-jian-de-lian-biao-wen-ti-h-2/
