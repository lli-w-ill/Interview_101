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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *oldHead = head;
        // 首先将头指针移动到第一个不重复的节点
        while (head && head->next) {
            if (head->val == head->next->val) {
                if (head->next->next == nullptr) {
                    head = nullptr;
                    break;
                }
                head = head->next;
            } else {
                if (head == oldHead) {
                    // [1,2,5]
                    //  ^
                    // head
                    break;
                }
                if (head->next->next && head->next->val != head->next->next->val) {
                    // [1,1,1,2,3,3]
                    //      ^ ? ?
                    //     head
                    head = head->next;
                    break;
                } else if (head->next->next && head->next->val == head->next->next->val) {
                    // [1,1,1,2,2,3,3]
                    //      ^ ? ?
                    //     head
                    head = head->next;
                } else if (head->next->next == nullptr) {
                    // [1,1,1,2]
                    //      ^ ?
                    head = head->next;
                    break;
                }
            }
        }
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *slow = head;      // slow 指向当前最后一个不重复的 node
        ListNode *fast = head->next;
        while (fast->next) {
            cout << slow->val << " " << fast->val << endl;
            if (fast->val == fast->next->val) {
                fast = fast->next;
            } else {
                // 查看 fast 是否指向 slow->next 重复序列的最后一个序列 
                if (slow->next != fast && slow->next->val == fast->val) {
                    // fast 当前指向 slow->next 重复序列的最后一个 node
                    fast = fast->next; // 先更新 fast 到下一个节点
                    // 删除从 slow->next 开始到 fast 前一个节点为止的所有节点
                    ListNode *temp = slow->next;
                    while (temp != fast) {
                        ListNode *next = temp->next;
                        temp->next = nullptr;
                        delete temp;
                        temp = next;
                    }
                    // 让 slow->next 等于 fast，跳过删除的重复序列
                    slow->next = fast;
                } else if (slow->next == fast) {
                    // fast 当前指向 slow->next，且 fast 与它下一个节点不相同
                    slow = fast;
                    fast = fast->next;
                }
            }
        }
        // 再检查 slow->next 和 fast 的 val 是否相同
        if (slow->next != fast && slow->next->val == fast->val) {
            // fast 当前指向 slow->next 重复序列的最后一个 node
            // 删除从 slow->next 开始到 fast 为止的所有节点
            ListNode *temp = slow->next;
            while (temp != nullptr) {
                ListNode *next = temp->next;
                temp->next = nullptr;
                delete temp;
                temp = next;
            }
            // 将最后一个不重复的 next 指针置为 nullptr
            slow->next = nullptr;
        }

        return head;
    }
};
