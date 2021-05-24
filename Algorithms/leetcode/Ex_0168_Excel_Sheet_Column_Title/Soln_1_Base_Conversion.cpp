#include <string>
#include <vector>
#include <algorithm>    // reverse
#include <iostream>

using std::string;
using std::vector;
using std::reverse;
using std::ostream;
using std::cout;
using std::endl;

ostream& operator<< (ostream& out, const vector<int> &v) {
    out << "[ ";
    for (const int &num : v) {
        out << num << " ";
    }
    out << "]";
    return out;
}

class Solution_1 {
private:
    // 返回 base10 数字的「26进制数字」
    // 注意这里的「26进制数字」是 1~26 的变种，而不是原声的 0~25
    vector<int> convertToBase26(int base10) {
        vector<int> base26;

        while (base10 > 0) {
            int quotient = (base10 - 1) / 26;
            int remainder = (base10 - 1) % 26;
            
            base26.push_back(remainder);

            base10 = quotient;
        }

        // 逆序的 base26 才是 base10 转换后的「变种26进制数」
        reverse(base26.begin(), base26.end());

        return base26;
    }

public:
    string convertToTitle(int columnNumber) {
        vector<int> base26 = convertToBase26(columnNumber);

        cout << base26 << endl;
        
        string res("");
        for (int &offset : base26) {
            res += ('A' + offset);
        }

        return res;
    }
};

// 建议配合 Ex.504 Base 7 一起做
// 进制转换过程：https://leetcode-cn.com/problems/base-7/solution/li-kou-jia-jia-jin-zhi-zhuan-hua-wen-ti-33xjw/
// 参考题解（推荐）：https://leetcode-cn.com/problems/excel-sheet-column-title/solution/jin-zhi-zhuan-huan-de-bian-chong-by-qyun-t5e5/
//
// 设 N = base26.size()
// time complexity: O(N)
// space complexity: O(N)
