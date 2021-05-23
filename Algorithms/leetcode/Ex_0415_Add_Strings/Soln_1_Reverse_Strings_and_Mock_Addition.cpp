#include <string>

using std::string;
using std::reverse;
using std::swap;
using std::to_string;

class Solution_1 {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();

        // 因为加法是从个位开始累加的，所以翻转字符串
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // 始终保证 num1 的长度小于等于 num2
        if (size1 >= size2) {
            swap(num1, num2);
            swap(size1, size2);
        }

        // 模拟加法过程
        int carry = 0;      // 计算进位
        string res ("");    // 保存最终结果
        // 先计算 num1 和 num2 的公共部分
        int i;
        for (i = 0; i < size1; i++) {
            int cur = (num1[i] - '0') + (num2[i] - '0') + carry;
            res += to_string(cur % 10);
            carry = cur / 10;
        }
        // 然后计算 num2 多出来的位数
        while (i < size2) {
            int cur = (num2[i] - '0') + carry;
            res += to_string(cur % 10);
            carry = cur / 10;
            i += 1;
        }
        // 最后再检查一遍进位
        if (carry > 0) {
            res += "1";
        }

        // 最后将结果再翻转回去
        reverse(res.begin(), res.end());

        return res;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

