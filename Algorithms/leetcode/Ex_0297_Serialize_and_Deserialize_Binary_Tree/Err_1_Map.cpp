#include <string>
#include <iostream>
#include <map>
#include <utility>

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::to_string;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Err_1 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        unsigned long long tag = 1.0;   // node 比较多时 int 会越界
        return dfs(root, tag);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        if (data.size() == 0) {
            return nullptr;
        }
        // cout << data << endl;
        
        map<unsigned long long, TreeNode*> tag2TreeNode;
        string nodeDelimiter = ","; // 分割 nodes 的分割符
        string tagDelimiter = "|";  // 分割 tag 和 node->val 的分割符

        // 找到每个node
        string token;
        size_t pos = 0;
        while ((pos = data.find(nodeDelimiter)) != string::npos) {
            token = data.substr(0, pos);

            // 分割 tag 和 node->val
            size_t tagPos = token.find(tagDelimiter);
            unsigned long long tag = stoull(token.substr(0, tagPos));
            int nodeVal = stoull(token.substr(tagPos+1, token.size() - tagPos));
            // cout << tag << " " << nodeVal << endl;

            // 创建 TreeNode 并加入到 tag2TreeNode 中
            tag2TreeNode.insert(pair<unsigned long long, TreeNode*> (tag, new TreeNode(nodeVal)));

            // 缩短字符串
            data.erase(0, pos + nodeDelimiter.length());
        }
        // 此时 data 应该剩下最后一个node的字符串
        // 分割最后一个 node 的 tag 和 node->val
        size_t tagPos = data.find(tagDelimiter);
        unsigned long long tag = stoull(data.substr(0, tagPos));
        int nodeVal = stoull(data.substr(tagPos+1, token.size() - tagPos));
        // cout << tag << " " << nodeVal << endl;
        // 创建最后一个node，并加入到 tag2TreeNode 中
        tag2TreeNode.insert(pair<unsigned long long, TreeNode*> (tag, new TreeNode(nodeVal)));

        // 链接 tag2TreeNode 中所有节点的左右孩子
        for (map<unsigned long long, TreeNode*>::iterator it = tag2TreeNode.begin(); it != tag2TreeNode.end(); it++) {
            unsigned long long tag = it->first;

            if ((tag & 1) == 0 && tag2TreeNode.find(tag / 2) != tag2TreeNode.end()) {   // 注意优先级 & < ==
                // 偶数tag（某个节点的左孩子）
                tag2TreeNode[tag / 2]->left = it->second;
            }
            if ((tag & 1) == 1 && tag2TreeNode.find((tag - 1) / 2) != tag2TreeNode.end()) { // 注意优先级 & < ==
                // 奇数tag（某个节点的有孩子）
                tag2TreeNode[(tag - 1) / 2]->right = it->second;
            }
        }
        
        // 返回根结点
        return tag2TreeNode[1];
    }

private:
    string dfs(TreeNode *cur, unsigned long long tag) {
        if (cur == nullptr) {
            return "";
        }
        string leftStr = dfs(cur->left, tag * 2);
        // I use '|' to delimit the tag and node value
        string curStr = to_string(tag) + "|" + to_string(cur->val);
        string rightStr = dfs(cur->right, tag * 2 + 1);

        // concatenate 3 strings
        string res;
        if (leftStr.size() > 0) {
            res += leftStr + ",";
        }
        res += curStr;
        if (rightStr.size() > 0) {
            res += "," + rightStr;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// C++分割字符（相当于其他语言中的split()）参考：https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
