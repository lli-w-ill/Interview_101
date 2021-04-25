#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution_3 {
public:
    string minWindow(string s, string t) {
        // key: t 中出现的字符
        // value: 该字符在 t 中出现的次数（也表示 windows 还需要再包括多少个字符 key，负数表示多包含了）
        unordered_map<char, int> chars;
        // key: t 中出现的字符
        // value: 该字符是否在 t 中出现
        unordered_map<char, bool> appear;

        int tSize = t.size();
        int sSize = s.size();

        // 记录 t 中出现的字符和出现的次数
        for (int i = 0; i < tSize; i++) {
            if (appear.count(t[i])) {
                chars[t[i]] ++;
            } else {
                chars.insert({t[i], 1});
                appear.insert({t[i], true});
            }
        }

        int l = 0;      // 左边界
        int min_l = 0;  // 最小 window 时的左边界
        int cnt = 0;    // 记录有多少 t 中的字符已经包含在当前 windows 中了
        int ws = sSize + 1;     // 最小的 window size, 初始时设为最大+1

        // 开始移动 rl 指针
        for (int r = 0; r < sSize; r++) {   // r: 右边界
            if (appear[s[r]]) {
                // 如果当前 s 中的字符在 t 中出现过，需要做处理；否则直接下一位
                // 递减 window 中还需要在包括的 s[r] 字符
                chars[s[r]] --;
                if (chars[s[r]] >= 0) {
                    // 只有 window 中字符 s[r] 还没有超过 t 中该字符的总数量时，才递增 cnt
                    // （如果 windows 对于 s[r]，包括的数量已经超过了 t 中本来有的该字符数量，那么在引入 s[r]，也不能累加 cnt）
                    cnt ++;
                }

                // 如果当前 window 中已经包含了 t 中所有字符，那么在不影响「window中包括t的所有字符」情况下，向右移动 l，求尽可能小的子串
                while (cnt == tSize) {
                    if (r - l + 1 < ws) {
                        // 更新最小的 window size，并同时记录当前时的 l 作为最有情况下的 l
                        ws = r - l + 1;
                        min_l = l;
                    }
                    
                    if (appear[s[l]]) {
                        // 如果 s[l] 出现在 t 中，则递增 chars
                        chars[s[l]] ++;
                        if (chars[s[l]] > 0) {
                            // 说明再右移 l，当前 window 就不能包括 t 中所有的字符了
                            cnt --;
                        } 
                    }

                    // 右移 l，最后一次循环，虽然再右移 l 就不全包含 t 中所有字符了，但是因为最优的（更短的）子串可能还在右边，所以不能马上返回。要把 l 右移一位使得状态不合法，然后再继续往右找
                    l ++;
                }
            }
        }

        if (ws == sSize + 1) {
            // 说明包含 t 中所有字符的子串不存在，因为 ws 从不曾更新过
            return "";
        } else {
            return s.substr(min_l, ws);
        }

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394


