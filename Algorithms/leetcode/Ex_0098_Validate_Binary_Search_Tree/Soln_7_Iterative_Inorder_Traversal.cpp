#include <vector>
#include <stack>

using std::vector;
using std::stack;

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

class Solution_7 {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        stack<TreeNode*> nodes;
        TreeNode *preLeftmost = nullptr;    // 指向中序遍历中 leftmost 的前一个节点

        while (!nodes.empty() || root != nullptr) {
            // 如果当前 node 还有左孩子就先把当前节点 push 到栈中，因为中序要先访问左子树
            while (root != nullptr) {
                nodes.push(root);
                root = root->left;
            }
            // 到这里应该已走到最左边了
            TreeNode *leftmost = nodes.top();
            nodes.pop();

            // 检查 preLeftmost 和 leftmost 的大小
            if (preLeftmost != nullptr && preLeftmost->val >= leftmost->val) {
                return false;
            }

            // 更新 preLeftmost
            preLeftmost = leftmost;

            // 访问右子树
            root = leftmost->right;
        }

        return true;
    }
};
