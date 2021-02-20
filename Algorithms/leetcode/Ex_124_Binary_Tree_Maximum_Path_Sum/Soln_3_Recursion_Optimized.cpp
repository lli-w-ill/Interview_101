#include <iostream>
#include <algorithm>

using std::max;

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

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }

private:
    int maxPathSum(TreeNode *node, int &res) {
        if (node == nullptr) {
            return 0;
        }
        // 左边分支的最大值（这个最大值应该也是path sum最大的「一直向下的单链」的路径和）
        // 与0取大是因为：如果path sum最大的单链的路径和都是负数，那还不是不加
        int leftMax = max(0, maxPathSum(node->left, res));
        // 右边分支的最大值（同上）
        int rightMax = max(0, maxPathSum(node->right, res));
        // 以当前node为root的max path sum和历史最大值取大值
        res = max(res, node->val + leftMax + rightMax);
        // 以node的单边最大分支和当前node 一起组成的path sum，返回给node的父节点
        return node->val + max(leftMax, rightMax);
    }
};

// 解法参考（推荐）：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/
// 解法参考的@cheney热评注解非常有帮助！
// 相比我写的Soln_1真的简洁了好多-w-
