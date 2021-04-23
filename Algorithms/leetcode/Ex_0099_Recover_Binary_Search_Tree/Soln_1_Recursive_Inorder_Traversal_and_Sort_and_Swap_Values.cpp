#include <vector>
#include <map>

using std::vector;
using std::map;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_1 {
public:
    void recoverTree(TreeNode* root) {
        // key: val
        // value: 节点指针
        map<int, TreeNode*> inOrderMap;
        vector<int> inOrderVec;

        // 中序遍历
        inOrderTraversal(root, inOrderVec, inOrderMap);

        // 找到中序遍历中位置不对的值
        vector<int> copyInOrderVec (inOrderVec.begin(), inOrderVec.end());
        sort(copyInOrderVec.begin(), copyInOrderVec.end());
        vector<int> diffTwoIndices;
        for (int i = 0; i < inOrderVec.size(); i++) {
            if (inOrderVec[i] != copyInOrderVec[i]) {
                diffTwoIndices.push_back(inOrderVec[i]);
            }
        }
        // cout << diffTwoIndices.size();
        if (diffTwoIndices.size() != 2) {
            return;
        }

        // 交换 diffTwoIndices 中两个值所对应的 nodes
        TreeNode *node1 = inOrderMap[diffTwoIndices[0]];
        TreeNode *node2 = inOrderMap[diffTwoIndices[1]];
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }

private:
    void inOrderTraversal(TreeNode *cur, vector<int> &inOrderVec, map<int, TreeNode*> &inOrderMap) {
        if (cur == nullptr) {
            return;
        }

        inOrderTraversal(cur->left, inOrderVec, inOrderMap);

        inOrderVec.push_back(cur->val);
        inOrderMap.insert({cur->val, cur});

        inOrderTraversal(cur->right, inOrderVec, inOrderMap);
    }
};

// 一共有 N 个 nodes
// 时间复杂度：O(N * logN)
// 空间复杂度：O(N)
