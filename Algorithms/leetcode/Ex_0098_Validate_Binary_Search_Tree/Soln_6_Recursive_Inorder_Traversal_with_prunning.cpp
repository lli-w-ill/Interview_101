#include <vector>

using std::vector;

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

class Solution_6 {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        return inOrderTraversal(root, inOrder); 
    }

private:
    // cur 代表当前要检查的 bst 的根
    // val 代表当前树中节点要「大于 min 且小于 max」 的基准
    bool inOrderTraversal(TreeNode *cur, vector<int> &inOrder) {
        if (cur == nullptr) {
            return true;
        }
        
        // 先插入左子树
        bool leftValid = inOrderTraversal(cur->left, inOrder);
        if (!leftValid) {
            return false;
        }

        // 当插入当前值时，检查当前 val 和中序最后一个数字的大小
        if (!inOrder.empty() && cur->val <= inOrder[inOrder.size()-1]) {
            return false;
        }
        inOrder.push_back(cur->val);

        // 最后插入右子树
        bool rightValid = inOrderTraversal(cur->right, inOrder);
        if (!rightValid) {
            return false;
        }

        return true;
    }
};
