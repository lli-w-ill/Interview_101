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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        if (head->next->next == nullptr) {
            // 特判：有两个节点的情况
            return head->val == head->next->val;
        }
        ListNode *slow = head;
        ListNode *preSlow = nullptr;    // 保存上一次循环的 slow
        ListNode *postSlow = nullptr;   // 保存当前循环中 slow->next
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            // 移动slow + 翻转链表前半部分的链表
            postSlow = slow->next;
            slow->next = preSlow;
            preSlow = slow;
            slow = postSlow;
            
            // 移动fast
            fast = fast->next->next;
        }
        // 此时，
        // 1. 如果链表长度为奇数:
        //      fast = nullptr
        //      slow 应该指向的是链表的中点node，且slow左边的node（不包括slow）的next指针都已反转
        //      preSlow可以当作左边链表的head1
        //      postSlow->next可以当作右边链表的head2
        // 2. 如果链表长度是偶数: 
        //      fast = last node
        //      slow应该指向的是链表中点两个node的靠左边的node，且slow的next指针还没有修改
        //      需要先反转slow.next，然后slow可以当作左边链表的head1
        //      postSlow可以当作右边链表的head2
        ListNode *head1 = nullptr;
        ListNode *head2 = nullptr;
        if (fast == nullptr) {
            // 链表长度为奇数
            // x     1 --> 2 --> 3 --> 2 --> 1 --> x
            // pre   s  post/f
            //
            // x <-- 1 --> 2 --> 3 --> 2 --> 1 --> x
            //      pre    s    post   f
            //
            // x <-- 1 <-- 2 --> 3 --> 2 --> 1 --> x
            //            pre   s/post             f   (break)
            head1 = preSlow;
            // 注意点2: 解释同下面
            head2 = postSlow->next;
        } else {
            // 链表长度是偶数
            // x     1 --> 2 --> 3 --> 3 --> 2 --> 1 --> x
            // pre   s  post/f
            //
            // x <-- 1 <-- 2 --> 3 --> 3 --> 2 --> 1 --> x
            //      pre    s   post    f
            //
            // x <-- 1 <-- 2 --> 3 --> 3 --> 2 --> 1 --> x
            //            pre   s/post             f
            // 注意点1: 这里一定要先设head2，然后再修改slow->next
            // 注意点2: 这里s (slow) 是与post (postSlow)在同样一个位置的，因为根据图可以 f 移动了两次，也就是 while 执行了两次，而post是在while最开始才赋值的，所以最开始也算一次！！并且因为是先给post赋值，赋值pre、移动slow，所以最后一次循环pre和post向前推进的情况并不相同
            head2 = postSlow->next;   
            slow->next = preSlow;
            head1 = slow;
        }
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};

// 思路：找到链表的中点，然后在找中点的时候，逆转链表的前半部分，然后从中点分别向两遍走
