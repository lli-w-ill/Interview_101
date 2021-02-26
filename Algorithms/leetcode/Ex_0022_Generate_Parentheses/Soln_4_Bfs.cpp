#include <string>
#include <vector>
#include <queue>

using std::string;
using std::vector;
using std::queue;

class Node {
public: 
    // 当前得到的字符串
    string str;
    // 剩余左括号数量
    int left;
    // 剩余右括号数量
    int right;

    Node(string s, int l, int r) : str {std::move(s)}, left {l}, right{r} {
    }
};

class Solution_4 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) {
            return res;
        }
        queue<Node> queue;
        queue.push(Node("", n, n));
        while (!queue.empty()) {
            Node curNode = queue.front();
            queue.pop();
            if (curNode.left == 0 && curNode.right == 0) {
                // 结算
                res.push_back(curNode.str);
            }
            if (curNode.left > 0) {
                queue.push(Node(curNode.str + "(", curNode.left - 1, curNode.right));
            }
            if (curNode.right > 0 && curNode.left < curNode.right) {
                // 只有左括号剩余比右括号少时（即左括号使用的比右括号多时），才能添加右括号
                queue.push(Node(curNode.str + ")", curNode.left, curNode.right - 1));
            }
        }
        return res;
    }
};

// 参考题解：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
