#include <iostream>
#include <map>

using std::map;

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


class Solution_1 {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }

        map<Node*, Node*> mp;

        // 第一遍，创建所有新节点
        Node *cur = head;
        while (cur != nullptr) {
            // 创建一个拷贝节点
            Node *copy = new Node(cur->val);
            mp.insert({cur, copy});
            cur = cur->next;
        }

        // 第二遍，赋值 next, random 指针
        cur = head;
        while (cur != nullptr) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        
        return mp[head];
    }
};
