#include <map>

using std::map;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 特判
        if (head == nullptr || k == 0 || k == 1) {
            return head;
        }
        
        // 记录当前的头节点
        ListNode *curHead = head;

        // 首先尝试找到第 k 个节点（向前移动个 k-1 次 head）
        int cnt;
        for (cnt = 1; cnt < k; cnt++) {
            head = head->next;
        }
        if (cnt < k) {
            // 说明当前链表不足 k 个节点，无法交换，直接返回
            return curHead;
        }

        ListNode *preHead = nullptr;
        ListNode *preTail = nullptr;
        while (curHead) {
            // 找到当前组的结尾，并同时边找边向 mp 中赋值
            // key: 序号 1 ~ k
            // value: 节点指针
            map<int, ListNode*> mp;
            int key = 1;
            ListNode *curTail = curHead;
            while (curTail && key < k) {
                mp.insert({key, curTail});
                curTail = curTail->next;
                key ++;
            }
            // 将当前组最后一个节点甲级加进来最后一个
            if (curTail == nullptr || key < k) {
                // 当前组只有 k-1 个，不交换直接退出
                break;
            } else {
                mp.insert({k, curTail});
            }

            // 到达了 k 个，逐一交换
            // 首先记录下一组的头节点
            ListNode *nextHead = curTail->next;
            // 开始交换
            for (int i = k; i > 1; i--) {
                mp[i]->next = mp[i-1];
            }
            // 交换后的头节点应该连接上一组的尾节点
            if (preTail != nullptr) {
                // cout << preTail->val << " " << mp[k]->val << endl;
                preTail->next = mp[k];
            }
            // 更新尾节点为「当前组的尾节点」
            preTail = mp[1];

            // 更新下一组的头节点
            curHead = nextHead;
            // 先让当前的尾节点指向下一组的头节点，这样如果下一组不够 k 个的话就不用再加上额外的判断；而如果下一组够 k 个的话下一轮也会通过 preTail 被覆盖掉
            mp[1]->next = curHead;
        }
        
        return head;
    }
};

// 设原链表长度为 N
// Time Complexity: O(N * k)
// Space Complexity: O(k)
