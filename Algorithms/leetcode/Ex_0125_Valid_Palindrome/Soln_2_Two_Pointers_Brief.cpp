#include <string>
#include <locale>   // std::isalnum
#include <cctype>   // std::tolower

using std::string;
using std::isalnum;
using std::tolower;

class Solution_2 {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l])) 
                l ++;
            while (r > l && !isalnum(s[r])) 
                r --;
            if (l < r && tolower(s[l++]) != tolower(s[r--]))
                return false;
        }

        return true;
    }
};

// 参考题解：https://leetcode-cn.com/problems/valid-palindrome/solution/c6xing-you-mei-dai-ma-by-xiaohu9527-507o/
