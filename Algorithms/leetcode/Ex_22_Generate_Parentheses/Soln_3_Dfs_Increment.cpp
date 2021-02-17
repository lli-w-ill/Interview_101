#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution_3 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) {
            return res;
        }
        dfs("", 0, 0, n, res);
        return res;
    }

    void dfs(string str, int left, int right, int n, vector<string> &res) {
        if (left == n && right == n) {
            // 结算
            res.push_back(str);
            return;
        }
        // 剪枝
        if (left < right) {
            // 右括号不能比左括号使用的还多，即左括号要先于右括号
            return;
        }
        if (left < n) {
            dfs(str + "(", left + 1, right, n, res);
        }
        if (right < n) {
            dfs(str + ")", left, right + 1, n, res);
        }
    }
};

// 参考：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
