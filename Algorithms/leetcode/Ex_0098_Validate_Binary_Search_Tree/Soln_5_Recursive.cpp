#include <iostream>

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

class Solution_5 {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    // cur 代表当前要检查的 bst 的根
    // val 代表当前树中节点要「大于 min 且小于 max」 的基准
    bool isValidBST(TreeNode *cur, long min, long max) {
        // base case
        if (cur == nullptr) {
            return true;
        } else if (cur->val <= min || cur->val >= max) {
            // 不满足要求
            return false;
        } else if (cur->left == nullptr && cur->right == nullptr) {
            // 满足要求的叶子节点
            return true;
        }

        // 开始递归
        long curVal = cur->val; // 这里需要转成 long 型，因为 std::min, std::max 不能自动转换参数的类型，必须接受相同类型的参数
        if (cur->right == nullptr) {
            // 当前节点只有左孩子
            // 左子树中所有节点要小于 min(cur->val, max)：保持 min，更新 max
            return cur->val > cur->left->val 
                && isValidBST(cur->left, min, std::min(curVal, max));
        } else if (cur->left == nullptr) {
            // 当前节点只有右孩子
            // 右子树中的所有节点要大于 max(cur->val, min)：更新 min，保持 max
            return cur->val < cur->right->val 
                && isValidBST(cur->right, std::max(curVal, min), max);
        } else {
            // 优化点：这里可以直接写到 return 里利用「&的短路」特性也许可以免去算 isRightSubtreeValid 的时间
            bool isLeftSubtreeValid = isValidBST(cur->left, min, std::min(curVal, max));
            bool isRightSubtreeValid = isValidBST(cur->right, std::max(curVal, min), max);
            // 当前节点既有左孩子也有右孩子
            return cur->val > cur->left->val 
                && cur->val < cur->right->val 
                && isLeftSubtreeValid
                && isRightSubtreeValid;
        }
    }
};
