#include <cstdlib>

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

class Solution_2 {
private:
    ListNode *head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution_2(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        // 蓄水池随机抽样
        // 算法解释见《刷题笔记》第 78 页
        int res = this->head->val;

        // 从第二个节点开始
        ListNode *cur = this->head->next;
        int m = 2;
        while (cur != nullptr) {
            if (rand() % m == 0) {
                // 有 1/m 的几率让当前节点的 cur->val 覆盖掉之前的选择
                res = cur->val;
            }

            m ++;
            cur = cur->next;
        }

        return res;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

 // 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
 