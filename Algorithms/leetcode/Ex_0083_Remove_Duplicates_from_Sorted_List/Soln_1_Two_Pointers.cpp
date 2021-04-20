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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = head;
        while (prev) {
            ListNode *next = prev->next;
            while (next && next->val == prev->val) {
                next = next->next;
            }
            prev->next = next;
            prev = next;
            if (prev) {
                // 判断是否 prev 已经到了最后一个节点的空next节点
                next = prev->next;
            }
        }
        
        return head;
    }
};
