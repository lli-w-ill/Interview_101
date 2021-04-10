#include <vector>

using std::vector;

class Solution_3 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int total = 0;      // 目前为止的总油量 - 耗油量
        int leftGas = 0;    // 剩余油量
        int startPos = 0;

        for (int i = 0; i < size; i++) {
            int currLeft = gas[i] - cost[i];
            total += currLeft;
            leftGas += currLeft;
            if (leftGas < 0) {
                leftGas = 0;
                startPos = i + 1;  // 这里并不是 start++，因为如果从 A 出发，卡到了加油站 B，那么从 A ... B 之间任意一个加油站出发都会再次卡到 B，所以直接从 B 的下一个加油站出发继续尝试
            }
        }

        return total >= 0 ? startPos : -1;
    }
};

// 参考之前账号提交记录

