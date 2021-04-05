#include <vector>

using std::vector;

class Solution_3 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        
        int up = 0;     // 上边界 (upper bound) 
        int down = matrix.size() - 1;       // 下边界 (lower bound)
        int left = 0;   // 左边界 (left bound)
        int right = matrix[0].size() - 1;   // 右边界 (right bound)
        
        while (true) {
            // 向右移动直到最右
            for (int i = left; i <= right; i++)
                res.push_back(matrix[up][i]);
            if (++up > down)    // 上边界向下「压」
                // 如果上边界大于下边界，则遍历完成
                break;

            // 向下移动到最下
            for (int i = up; i <= down; i++)
                res.push_back(matrix[i][right]);
            if (--right < left)    // 右边界向左「压」
                // 如果右边界小于左边界，则遍历完成
                break;

            // 向左移动到最左
            for (int i = right; i >= left; i--)
                res.push_back(matrix[down][i]);
            if (--down < up)    // 下边界向上「压」
                // 如果下边界小于上边界，则遍历完成
                break;
            
            // 向上移动到最上
            for (int i = down; i >= up; i--)
                res.push_back(matrix[i][left]);
            if (++left > right) // 左边界向右「压」
                // 如果左边界超过右边界，则遍历结束
                break;
        }

        return res;
    }
};

// 参考题解（推荐）：https://leetcode-cn.com/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/

