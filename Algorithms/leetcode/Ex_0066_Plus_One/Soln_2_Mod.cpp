#include<vector>

using std::vector;

class Solution_2 {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] ++;
            digits[i] %= 10;
            if (digits[i] != 0)
                return digits;
        }
        vector<int> digitsNew(digits.size() + 1);
        digitsNew[0] = 1;
        return digitsNew;
    }
};

// 参考题解：https://leetcode-cn.com/problems/plus-one/solution/hua-jie-suan-fa-66-jia-yi-by-guanpengchn/
