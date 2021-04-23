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

class Solution_5 {
public:
    bool isPalindrome(ListNode* head) {
        // 特判
        if (head == nullptr) {
            return true;
        }

        // 步骤1: 找到前半部分链表的尾节点
        ListNode *firstHalfEnd = endOfFirstHalf(head);

        // 步骤2: 反转后半部分链表
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

        // 步骤3: 判断是否回文
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        bool res = true;
        while (res && p2 != nullptr) {
            if (p1->val != p2->val) {
                res = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // 这里因为无论原链表长度是奇数还是偶数，如果是回文，p1 和 p2 一定同时到达各自一半链表的结尾，而且前一半链表的后面是后一半链表，所以只要判断后边一半链表的指针是否为空就可以了

        // 步骤4: 恢复链表（非常重要）
        firstHalfEnd->next = reverseList(secondHalfStart);

        return res;
    }

private:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            // 首先保存当前节点的后一个节点
            ListNode *curNext = cur->next;
            // 反转当前节点的 next 指针
            cur->next = pre;
            // 更新 pre, cur
            pre = cur;
            cur = curNext;
        }
        return pre;
    }

    ListNode* endOfFirstHalf(ListNode *head) {
        // 利用快慢指针求中间节点
        // 如果是奇数，则中间节点唯一
        // 如果是偶数，则返回靠左边的那个中间节点
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode-solution/
// 思路：将链表的后半部分反转，然后将前半部分与后半部分比较
// 空间复杂度：O(1)
// 这种解法的缺点：在并发环境下，函数运行时需要锁定其他线程或进程对链表的访问，因为在函数执行过程中链表会被修改
// 注意：一定要在判断回文后恢复链表，Soln_1中就忘了恢复，虽然程序可以通过，但是调用「判断回文函数」的程序的原生链表会被修改！
