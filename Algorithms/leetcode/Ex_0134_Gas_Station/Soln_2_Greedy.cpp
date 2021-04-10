#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution_2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        if (size == 1) {
            if (cost[0] > gas[0]) {
                return -1;
            } else {
                return 0;
            }
        }

        vector<pair<int, double>> ratio;
        ratio.reserve(size);

        // 计算 gas[i] / cost[i] 比例
        for (int i = 0; i < size; i++) {
            if (cost[i] == 0) {
                ratio.emplace_back(i, ((double) gas[i] / 1));
            } else {
                ratio.emplace_back(i, ((double) gas[i] / cost[i]));
            }
        }

        // 按照 ratio 从大到小排序
        sort(ratio.begin(), ratio.end(), [](const pair<int, double> &o1, const pair<int, double> &o2) {
            return o1.second >= o2.second;
        });

        // 从 ratio 最大的位置开始尝试
        for (int i = 0; i < size; i++) {
            int startPos = ratio[i].first;
            int gasLeft = gas[startPos] - cost[startPos];  // 初始油量（到下一个加油站前还能剩的油量）
            if (gasLeft < 0) {
                // 初始油量不支持到下一个加油站
                continue;
            }
            int j;
            for (j = (startPos + 1) % size; j != startPos; j = (j + 1) % size) {
                gasLeft = gasLeft - cost[j] + gas[j];
                if (gasLeft < 0) {
                    break;
                }
            }
            // 检查最终位置是否是起始位置
            if (j == startPos) {
                return startPos;
            }
        }

        return -1;
    }
};

// 参考之前账号提交记录
