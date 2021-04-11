#include <string>

using std::string;

class Solution_3 {
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.size();
        int res = 0;
        
        for (int i = 0; i < size; i++) {
            int num = columnTitle[i] - 'A' + 1;
            res = res * 26 + num;
        }

        return res;
    }
};

// 参考题解：https://leetcode-cn.com/problems/excel-sheet-column-number/solution/hua-jie-suan-fa-171-excelbiao-lie-xu-hao-by-guanpe/
