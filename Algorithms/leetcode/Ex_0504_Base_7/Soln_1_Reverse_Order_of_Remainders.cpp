#include <string>

using std::string;
using std::to_string;

class Solution_1 {
public:
    string convertToBase7(int num) {
        // 特判
        if (num == 0) {
            return "0";
        }

        bool isNeg = num < 0;
        if (isNeg) {
            num = -num;
        }

        string res = "";
        while (num > 0) {
            int quotient = num / 7;
            int remainder = num % 7;
            
            res = to_string(remainder) + res;
            num = quotient;
        }

        return isNeg == true ? "-" + res : res;

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
