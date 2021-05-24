#include <string>
#include <algorithm>    // reverse

using std::string;
using std::reverse;
using std::swap;

class Solution_1 {
public:
    string addBinary(string a, string b) {
        int sizea = a.size();
        int sizeb = b.size();

        // 始终保证 sizea <= sizeb
        if (sizea > sizeb) {
            swap(sizea, sizeb);
            swap(a, b);
        }

        // 要先翻转 a, b
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        // 相加后的结果加到 b 上面
        // 先相加 a 和 b 的重叠部分
        int i;
        int carry = 0;
        for (i = 0; i < sizea; i++) {
            int ia = a[i] - '0';
            int ib = b[i] - '0';

            if (ia + ib + carry > 1) {
                b[i] = (char)('0' + ((ia + ib + carry) % 2));
                carry = 1;
            } else {
                b[i] = (char)('0' + (ia + ib + carry));
                carry = 0;
            }
        }

        // 然后更新 b 多出来的部分
        for (; i < sizeb; i++) {
            int ib = b[i] - '0';
            
            if (ib + carry > 1) {
                b[i] = (char)('0' + ((ib + carry) % 2));
                carry = 1;
            } else {
                b[i] = (char)('0' + (ib + carry));
                carry = 0;
            }
        }
        if (carry == 1) {
            b += "1";
        }

        // 最终要翻转回来
        reverse(b.begin(), b.end());

        return b;
    }
};
