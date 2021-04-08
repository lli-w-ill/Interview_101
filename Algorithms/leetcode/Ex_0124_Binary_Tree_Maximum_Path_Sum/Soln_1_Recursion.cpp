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

class Solution_1 {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return INT_MIN;
        }
        // 第1种情况：最大路径和在左子树
        int leftMax = maxPathSum(root->left);
        // 第2种情况：最大路径和在右子树
        int rightMax = maxPathSum(root->right);
        // 第3种情况：最大路径和 = 当前节点的值
        int onlyCurNode = root->val;
        // 第4种情况：最大路径和是当前节点 + 以root.left为起点「一直向下的」单链最大路径和（单链表示路径是一直向下的，没有"折叠"，即某个点A和A.left和A.right都在路径上）
        int leftSingleMaxPathSum = findSingleMaxPathSum(root->left);
        int case4 = root->val + leftSingleMaxPathSum;
        // 第5种情况：最大路径和是当前节点 + 以root.right为起点「一直向下」单链最大路径和（与第4种相似）
        int rightSingleMaxPathSum = findSingleMaxPathSum(root->right);
        int case5 = root->val + rightSingleMaxPathSum;
        // 第6种情况：（= 第3种 + 第4种）是经过root的最大路径和
        int case6 = root->val + leftSingleMaxPathSum + rightSingleMaxPathSum;
        // cout << leftMax << " " << rightMax << " " << onlyCurNode << " " << case4 << " " << case5 << " " << case6 << endl;
        return max(leftMax, max(rightMax, max(onlyCurNode, max(case4, max(case5, case6)))));
    }

private:
    int findSingleMaxPathSum(TreeNode *node) {
        // node 为空
        if (node == nullptr) {
            return 0;
        }
        // node 为叶子结点
        if (node->left == nullptr && node->right == nullptr) {
            return node->val;
        }
        // node 只有单个孩子
        if (node->left == nullptr) {
            return node->val + max(0, findSingleMaxPathSum(node->right));   // 注意这里需要与0做比较，因为如果再往下走会让单链的path sum更小的话，就没必要再往下走了
        } else if (node->right == nullptr) {
            return node->val + max(0, findSingleMaxPathSum(node->left));    // 这里需要与0比较,理由同上
        }
        // node 有两个孩子
        return node->val + max(0, max(findSingleMaxPathSum(node->left), findSingleMaxPathSum(node->right)));    // 这里需要与0比较,理由同上
    }
};
