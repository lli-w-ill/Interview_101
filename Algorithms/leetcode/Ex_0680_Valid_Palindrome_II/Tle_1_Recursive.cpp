#include <string>

using std::string;

class Tle_1 {
public:
    bool validPalindrome(string s) {
        return checkPalindrome(s, 0, s.size() - 1, false);
    }

private:
    bool checkPalindrome(string s, int l, int r, bool removed) {
        if (l >= r) {
            return true;
        }
        if (s[l] != s[r]) {
            if (removed) {
                // 如果之前已经删除过一次字符了，又遇到了不匹配，则直接返回 false
                return false;
            } else {
                // 如果还没有使用「删除技能」，则分别对左边／右边使用一次技能，返回二者结果的logic or
                return checkPalindrome(s, l + 1, r, true) || checkPalindrome(s, l, r - 1, true);
            }
        } else {
            return checkPalindrome(s, l + 1, r - 1, removed);
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
