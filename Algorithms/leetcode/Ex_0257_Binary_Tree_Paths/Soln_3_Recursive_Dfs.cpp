#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) {
            return res;
        }
        dfs(root, "", res);
        return res;
    }

private:
    void dfs(TreeNode *cur, string path, vector<string> &res) {
        if (cur->left == nullptr && cur->right == nullptr) {
            path += to_string(cur->val);
            res.push_back(path);
            return;
        }

        if (cur->left) {
            // 修改当前节点状态：
            //      cur = cur->left
            //      path = path + to_string(cur->val) + "->"
            // 递归子节点
            // 每当退回到当前状态时，节点状态自动恢复
            dfs(cur->left, path + to_string(cur->val) + "->", res);
        }
        if (cur->right) {
            // 同上，修改当前节点状态、递归子节点、恢复当前节点状态 三者合并为一条语句
            dfs(cur->right, path + to_string(cur->val) + "->", res);
        }

    }
};

// // 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
