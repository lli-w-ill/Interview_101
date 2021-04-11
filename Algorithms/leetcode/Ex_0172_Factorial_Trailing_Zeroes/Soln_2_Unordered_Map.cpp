#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::min;

class Solution_2 {
public:
    int trailingZeroes(int n) {
        int two = 0;    // 因子 2 的个数
        int five = 0;   // 因子 5 的个数
        
        // key: i
        // val: i 包含 2 的因子数
        unordered_map<int, int> mp2;
        // key: i
        // val: i 包含 5 的因子数
        unordered_map<int, int> mp5;

        for (int i = 1; i <= n; i++) {
            int temp2 = i;
            int temp5 = i;

            int twoIncrement = 0;   // i 对因子数 2 的贡献数
            while (temp2 > 0 && temp2 % 2 == 0) {
                if (mp2.count(temp2)) {
                    twoIncrement += mp2[temp2];
                    break;
                }
                twoIncrement ++;
                temp2 /= 2;
            }
            mp2.insert({i, twoIncrement});
            two += twoIncrement;

            int fiveIncrement = 0;  // i 对因子数 5 的贡献数
            while (temp5 > 0 && temp5 % 5 == 0) {
                if (mp5.count(temp5)) {
                    fiveIncrement += mp5[temp5];
                    break;
                }
                fiveIncrement ++;
                temp5 /= 5;
            }
            mp5.insert({i, fiveIncrement});
            five += fiveIncrement;
        }

        return min(two, five);
    }
};

// 思路：因为尾0只由 因子2 和 因子5 相乘得到，所以计算 [1, n] 中所有数字因子2和因子5的个数
// 参考（c++ 中 map, unordered_map 对 count 操作的 time complexity）: https://thispointer.com/map-vs-unordered_map-when-to-choose-one-over-another/#:~:text=Time%20complexity%20for%20searching%20elements,searching%20is%20O(1).

