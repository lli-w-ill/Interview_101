#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution_2 {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return res;
        }

        vector<string> split;
        partition(s, 0, s.size(), split);

        return res;
    }

private:
    vector<vector<string>> res;

    void partition(const string &s, int startPos, int size, vector<string> &split) {
        if (startPos == size) {
            res.push_back(split);
        } else {
            for (int i = startPos; i < size; i++) {
                // 判断当前字符串 s[startPos ... i] 是否是回文串
                if (isPalindrome(s, startPos, i)) {
                    int length = i - startPos + 1;
                    split.push_back(s.substr(startPos, length));

                    // 继续分割 s[i+1 ... size)
                    partition(s, i + 1, size, split);

                    split.pop_back();
                }
            }
        }
    }

    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};

// 参考以前账号的提交记录
