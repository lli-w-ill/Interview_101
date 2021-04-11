#include <string>
#include <cmath>

using std::string;
using std::pow;

class Solution_2 {
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.size();

        int res = 0;
        int power = pow(26, size - 1);
        for (int i = 0; i < size; i++) {
            res += (columnTitle[i] - 'A' + 1) * power;
            power /= 26;
        }

        return res;
    }
};
