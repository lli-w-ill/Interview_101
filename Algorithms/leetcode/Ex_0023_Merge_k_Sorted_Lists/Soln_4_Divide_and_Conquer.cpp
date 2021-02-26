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

class Solution_4 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid+1, right);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// 参考题解：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/leetcode-23-he-bing-kge-pai-xu-lian-biao-by-powcai/

// 相较于 Soln_2 的分治算法，该解法的用递归方法来两两合并链，这种解法虽然看起来代码简练，但是会占用更多占空间，可能会导致栈溢出，所以如果可以写成像 Soln_2 那种非递归（或者尾递归）的解法，尽量不要用递归解法
