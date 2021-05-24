#include <unordered_map>
#include <cstdlib>

using std::unordered_map;
using std::rand;

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
private:
    int length;
    unordered_map<int, ListNode*> ump;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution_1(ListNode* head) {
        // 计算长度，并将 (index, ListNode*) pair 存入到 ump
        int i;
        ListNode* cur = head;
        for (i = 0; cur != nullptr; cur = cur->next, i++) {
            ump.insert({i, cur});
        }
        length = i;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        // return ump[rand() % length]->val;
        return ump[rand() % length]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
