#include <unordered_map>

using std::unordered_map;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution_2 {
private:
    unordered_map<Node*, Node*> dic;

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        if (dic.count(head)) {
            return dic[head];
        }

        Node *root = new Node(head->val);
        
        // 在哈希表中保存新节点的指针
        // 记住 head 是 head指向节点的地址，而不是 head指针的地址，&head才是指针自己的地址
        dic[head] = root;

        // 递归拷贝 next, random 指针
        root->next = copyRandomList(head->next);
        root->random = copyRandomList(head->random);

        return root;
    }
};

// 参考题解：https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/ha-xi-biao-di-gui-jian-dan-yi-dong-by-vi-jdbq/
