#include <string>
#include <locale>   // std::isalnum
#include <cctype>   // std::tolower

using std::string;
using std::isalnum;
using std::tolower;

class Solution_1 {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l]))
                l ++;
            while (r > l && !isalnum(s[r]))
                r --;
            if (!compareCharIgnoreCase(s[l], s[r]))
                return false;
            l ++;
            r --;
        }

        return true;
    }

private:
    bool compareCharIgnoreCase(char c1, char c2) {
        if (tolower(c1) == tolower(c2))
            return true;
        else
            return false;
    }
};
