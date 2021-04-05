#include <vector>

using std::vector;

class Solution_1 {
public:
    vector<int> plusOne(vector<int>& digits) {

        int carry = 1;  // 把最开始的 +1 计作对最后一位的 carry
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            if (digits[i] == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }
        if (carry == 1) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
