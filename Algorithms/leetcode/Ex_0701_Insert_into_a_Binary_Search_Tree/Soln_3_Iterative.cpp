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

class Solution_3 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }
        
        TreeNode *cur = root;
        TreeNode *preCur = nullptr; // 记录 cur 的父节点
        while (cur != nullptr) {
            preCur = cur;
            
            if (cur->val > val) {
                cur = cur->left;
            } else if (cur->val <= val) {
                cur = cur->right;
            }
        }

        // 判断是插在 preCur 的左孩子还是有孩子
        if (preCur->val > val) {
            preCur->left = new TreeNode(val);
        } else if (preCur->val <= val) {
            preCur->right = new TreeNode(val);
        }

        return root;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/solution/701-er-cha-sou-suo-shu-zhong-de-cha-ru-cao-zuo-d-4/

