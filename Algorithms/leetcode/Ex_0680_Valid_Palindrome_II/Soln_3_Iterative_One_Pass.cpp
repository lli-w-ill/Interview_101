#include <string>

using std::string;

class Solution_3 {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        int prev_l = -1;    // 记录第一次尝试删除左边字符前的 l（当开始第二次尝试后，将 prev_l 置为-1，表示当前在第二次尝试的状态下）
        int prev_r = -1;    // 记录第一次尝试删除左边字符前的 r（当开始第二次尝试后，将 prev_r 置为-1，表示当前在第二次尝试的状态下）
        bool leftRemoved = false;   // 是否尝试过删除左边的字符
        bool rightRemoved = false;  // 是否尝试过删除右边的字符

        // 第一次尝试：如果遇到第一次不符合，则删除左边的字符
        while (l < r) {
            if (s[l] != s[r]) {
                if (leftRemoved == false) {
                    // 如果第一次遇到了不符合，先尝试删除左边的字符（「第一次尝试」）
                    // 先记录当前的 l, r，如果尝试删除左字符失败的话，用于恢复到当前状态，开始「第二次尝试」
                    prev_l = l;
                    prev_r = r;
                    // 删除左字符，并更新状态
                    l ++;
                    leftRemoved = true;
                } else if (leftRemoved == true) {
                    // 走到这里有两种情况：
                    // 1. 在第一次尝试删除左字符后，又遇到了不匹配，此时的状态 prev_l, prev_r 应该记录的是「第一次尝试」前的状态
                    // 2. 在第二次尝试过程中，遇到了不匹配，此时的状态 prev_l, prev_r 应该已经重置回了 -1
                    if (prev_l != -1 && prev_r != -1) {
                        // 情况1
                        // 首先恢复到「第一次尝试」删除左字符之前，然后重置 prev_l, prev_r 回 -1 表示：当前在「第二次尝试」过程中
                        l = prev_l;
                        r = prev_r;
                        prev_l = -1;
                        prev_r = -1;
                    } else if (prev_l == -1 && prev_r == -1) {
                        // 情况2
                        // 查看是否是「第二次尝试」过程中第一次遇到不匹配
                        if (rightRemoved) {
                            // 已经使用过「删除技能了」
                            return false;
                        } else {
                            // 第一次遇到不匹配，删除右字符
                            r --;
                            rightRemoved = true;
                        }
                    }
                }
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

// 注：
// 「第一次尝试」表示第一次遇到不匹配，然后删除左字符，继续往后匹配
// 「第二次尝试」表示「第一次尝试」失败后，回到「第一次尝试」删除左字符前的状态，尝试删除右字符，继续往后匹配
