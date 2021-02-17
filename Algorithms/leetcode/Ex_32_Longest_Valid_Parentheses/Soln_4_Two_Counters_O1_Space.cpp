#include <string>

using std::string;
using std::max;

class Solution_4 {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len <= 1) {
            return 0;
        }
        int left = 0;   // 遇到的左括号个数
        int right = 0;  // 遇到的右括号个数
        int maxLen = 0;
        // 首先从左往右扫
        //  * 遇到'('，left递增
        //  * 遇到')'，right递增
        //  * 如果right > left，两者都重置0
        //  * 如果right = left，计算最大长度right-left
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                left += 1;
            } else {
                right += 1;
            }
            if (right > left) {
                left = 0;
                right = 0;
            } else if (right == left) {
                maxLen = max(right+left, maxLen);
            }
        }
        // 重置
        left = 0;
        right = 0;
        // 其次从右往左扫
        //  * 遇到')'，right递增
        //  * 遇到'('，left递增
        //  * 如果left > right，两者都重置0
        //  * 如果left = right，计算最大长度right-left
        for (int j = len-1; j >= 0; j--) {
            if (s[j] == ')') {
                right += 1;
            } else {
                left += 1;
            }
            if (left > right) {
                left = 0;
                right = 0;
            } else if (left == right) {
                maxLen = max(right+left, maxLen);
            }
        }
        return maxLen;
    }
};

// 动画参考解法4（非常推荐）：https://leetcode.com/problems/longest-valid-parentheses/solution/
