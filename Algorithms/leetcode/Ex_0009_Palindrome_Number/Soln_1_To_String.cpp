#include <string>

using std::string;
using std::to_string;

class Solution_1 {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x >= 0 && x <= 9) {
            return true;
        }

        string s = to_string(x);
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    }
};
