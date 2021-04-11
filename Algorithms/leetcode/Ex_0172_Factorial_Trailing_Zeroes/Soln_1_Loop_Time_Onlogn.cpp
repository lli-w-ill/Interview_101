#include <algorithm>

using std::min;

class Solution_1 {
public:
    int trailingZeroes(int n) {
        int two = 0;    // 因子 2 的个数
        int five = 0;   // 因子 5 的个数
        
        for (int i = 1; i <= n; i++) {
            int temp2 = i;
            int temp5 = i;
            while (temp2 > 0 && temp2 % 2 == 0) {
                two ++;
                temp2 /= 2;
            }
            while (temp5 > 0 && temp5 % 5 == 0) {
                five ++;
                temp5 /= 5;
            }
        }

        return min(two, five);
    }
};
