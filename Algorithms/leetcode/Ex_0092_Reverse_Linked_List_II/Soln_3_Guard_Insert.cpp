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

class Solution_3 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 特判
        if (head == nullptr || left == right) {
            return head;
        }

        // 首先将 g 移动到第一个要反转的节点的前一个节点（如果头节点是第一个要反转的，g 就应该指向 dummyHead
        // 将 p 移动到第一个要反转的节点
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *g = dummyHead;
        ListNode *p = head;
        // 双指针向前推进 left-1 次
        for (int i = 0; i < left - 1; i++) {
            g = g->next;
            p = p->next;
        }

        // cout << g->val << " " << p->val << endl;

        // 每次将 p->next 指向的节点插入到 g 的后面
        // p 需要移动 right - left 次
        for (int i = 0; i < right - left; i++) {
            // 将 p->next 的前后两个节点相连，并将 p->next 插入到 g 的后面
            ListNode *next = p->next;   // 要删除并插入到 g 后面的节点
            p->next = next->next;
            next->next = g->next;
            g->next = next;
        }

        return dummyHead->next;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/java-shuang-zhi-zhen-tou-cha-fa-by-mu-yi-cheng-zho/
