#include <string>
#include <climits>  // INT_MAX, INT_MIN

using std::string;

class Solution_2 {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int res = 0;

        // 过滤前置空格
        while (s[i] == ' ') {
            i += 1;
        }

        // 检查是否为空
        if (i == s.size()) {
            return 0;
        }

        // 尝试读入符号
        if (s[i] == '-') {
            sign = -1;
            i += 1;
        } else if (s[i] == '+') {
            i += 1;
        }

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            // 一定要加上括号，否则可能会溢出
            res = res * 10 + (s[i] - '0');
            i += 1;
        }

        return res * sign;
    }
};

// 参考题解：https://leetcode-cn.com/problems/string-to-integer-atoi/solution/c-10xing-shi-xian-atoi-z-by-zrita-z007/
