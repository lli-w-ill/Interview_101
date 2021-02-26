#include <vector>

using std::vector;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(-1);
        ListNode *h = &head;
        if (lists.size() == 0) {
            return head.next;
        }
        while (lists.size() > 1) {
            // 两两合并
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i+=2) {
                ListNode *list1 = lists[i];
                ListNode *list2 = nullptr;
                if (i + 1 < lists.size()) {
                    // 如果所有链加起来是奇数，则最后一对只有一个链
                    list2 = lists[i+1];
                }
                mergedLists.push_back(merge(list1, list2));
            }
            // 将两两合并后的所有链赋给lists
            lists = mergedLists;
        }
        return lists[0];
    }

private:
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 != nullptr) {
            tail->next = l1;
        }
        if (l2 != nullptr) {
            tail->next = l2;
        }
        return dummy.next;
    }
};