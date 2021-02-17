package Algorithms.leetcode.Ex_22_Generate_Parentheses;

import java.util.List;
import java.util.ArrayList;

class Solution_2 {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        if (n == 0) {
            return res;
        }
        dfs("", n, n, res);
        return res;
    }

    private void dfs(String curr, int left, int right, List<String> res) {
        if (left == 0 && right == 0) {
            // 结算
            res.add(curr);
            return;
        }
        // 剪枝：左括号要先于右括号，即：())是不合法的
        if (left > right) {
            // 左括号剩余数比右括号剩余数量多
            return;
        }
        if (left > 0) {
            dfs(curr + "(", left - 1, right, res);
        }
        if (right > 0) {
            dfs(curr + ")", left, right - 1, res);
        }
    }
}

// 参考：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/