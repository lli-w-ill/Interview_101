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

class Solution_1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(-1);
        ListNode *h = &head;
        if (lists.size() == 0) {
            return head.next;
        }
        while (true) {
            ListNode* minNode = nullptr;
            int minNodeIdx = -1;
            bool finish = true;
            // 判断是否所有的头指针都指向了nullptr，若没有，则找到头节点最小的那个节点和它的下标
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr) {
                    finish = false;
                    if (minNode == nullptr || minNode->val > lists[i]->val) {
                        minNode = lists[i];
                        minNodeIdx = i;
                    }
                }
            }
            if (finish) {
                h->next = nullptr;
                break;
            } else {
                // cout << minNode->val << endl;
                h->next = minNode;
                h = h->next;
                lists[minNodeIdx] = lists[minNodeIdx]->next;
            }
        }
        return head.next;
    }
};