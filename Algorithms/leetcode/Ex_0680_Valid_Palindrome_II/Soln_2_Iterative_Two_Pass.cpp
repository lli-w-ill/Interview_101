#include <string>

using std::string;

class Solution_2 {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        bool removed = false;

        // 第一次尝试：如果遇到第一次不符合，则删除左边的字符
        while (l < r) {
            if (s[l] != s[r] && !removed) {
                // 第一次遇到不符合，使用技能，删除左边的字符
                l ++;
                removed = true;
            } else if (s[l] != s[r] && removed) {
                // 第二次遇到不符合，直接退出
                break;
            } else if (s[l] == s[r]) {
                l ++;
                r --;
            }
        }
        if (l >= r) {
            return true;
        }

        // 第二次尝试：如果遇到第一次不符合，则删除右边的字符
        l = 0;
        r = s.size() - 1;
        removed = false;

        while (l < r) {
            if (s[l] != s[r] && !removed) {
                // 第一次遇到不符合，使用技能，删除右边的字符
                r --;
                removed = true;
            } else if (s[l] != s[r] && removed) {
                // 第二次遇到不符合，直接退出
                break;
            } else if (s[l] == s[r]) {
                l ++;
                r --;
            }
        }
        if (l >= r) {
            return true;
        }

        return false;

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
