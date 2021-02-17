#include <string>

using std::string;

class Solution_3 {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len <= 1) {
            return 0;
        }
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                // 如果遇到')'，首先先出栈，然后查看栈是否为空
                //      如果为空，则将当前的下标push进栈，为下一个括号子串计算长度
                //      如果不为空，则计算括号子串长度，判断是否更新maxLen
                int topmost = st.top();
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    int secondTop = st.top();
                    if (i - secondTop > maxLen) {
                        maxLen = i - secondTop;
                    }
                }
            }
        }
        return maxLen;
    }
};

// 参考：https://leetcode.com/problems/longest-valid-parentheses/solution/
