#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution_3 {
public:
    int numDecodings(string s) {
        int size = s.size();
        // 特判1: s 为空
        if (size == 0) {
            return 0;
        }

        int preChar = s[0] - '0';   // 记录前一位字符的数值
        // 特判2: s 以 '0' 字符开头，则无法解码（因为 '0' 只有可能与前一位字符一起合并解码）
        if (preChar == 0) {
            return 0;
        }
        // 特判3: s 仅有一个非 '0' 字符
        if (size == 1) {
            return 1;
        }

        // dp[i] 表示 s[0 ... i) 的解法方法数
        // dp[0] 是 dummy 位（为了处理 s[0] 与 s[1] 可以合并解码时保证下标不越界。为什么 dummy 位的 dp 值为1 ？举个例子 s = "123"，当 i=2 时，我们正在考虑的是字符'2'，通过 for 循环中的 if 条件判断我们可以得到 '2' 是可以与其前面的 '1' 进行合并的，所以 "12"（即s[0 .. i) 一共有两种解码方法 -> [("1","2"), ("12")]），所以 dp[2] = dp[1] + dp[0]，此时 dp[1] 初始值为 1，所以为了让 dp[2] = 2，dp[0](即dummy位) 必须是 1 ）
        // dp[1] 表示字符串 s[0, 1) 的解码方法数，由于最开始除了字符 '0'，其他字符都可以被单个解码，所以先初始化时都置为 1
        vector<int> dp (size + 1, 1);

        for (int i = 2; i <= size; i++) {
            int curChar = s[i-1] - '0'; // 当前位的字符值

            if ((preChar == 0 || preChar > 2) && curChar == 0) {
                // 如果当前字符值为 0，那么当前字符一定要和之前的字符一起合并后解码
                // 但是如果前一位字符也是 0 或者 合并后不在 [1,26] 内，则整个字符串 s 一定无法被解码
                return 0;
            }

            if ((preChar == 1 && curChar >= 0 && curChar <= 9) || (preChar == 2 && curChar <= 6)) {
                // 如果当前字符(curChar) 可以和前一个字符(preChar) 合并的话
                // 则根据 curChar 判断当前是有一种解码方法，还是有两种解码方法
                if (curChar != 0) {
                    // 如果当前字符(curChar) 不是 '0' 的话，那么就存在两种解码方式：
                    //  1. 不与 preChar 合并，解码  -> dp[i-1]
                    //  2. 与 preChar 合并，解码    -> dp[i-2]
                    dp[i] = dp[i-1] + dp[i-2];
                } else if (curChar == 0) {
                    // 如果当前字符是 0 的话，那么只能选择上面的第 2 种解码方式
                    dp[i] = dp[i-2];
                }
            } else {
                // 如果当前字符(curChar) 不能与前一个字符(preChar) 合并的话
                // 那么只能选择上面的第 1 种解码方式
                dp[i] = dp[i-1];
            }

            // 更新 preChar，看下一位字符
            preChar = curChar;
        }

        return dp[size];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
