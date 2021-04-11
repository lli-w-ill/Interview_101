#include <string>
#include <cmath>

using std::string;
using std::pow;

class Solution_1 {
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.size();

        int res = 0;
        for (int i = 0; i < size; i++) {
            res += (columnTitle[i] - 'A' + 1) * pow(26, size - i - 1);
        }

        return res;
    }
};
