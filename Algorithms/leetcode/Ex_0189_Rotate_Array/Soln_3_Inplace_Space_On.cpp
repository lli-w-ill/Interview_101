#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution_3 {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        res.reserve(nums.size());

        int size = nums.size();
        k %= size;
        if (size == 1 || k == 0) {
            return;
        }

        // 记录已经赋值到其他未知的下标
        // 例如：[1,2,3,4] k = 1, 当 [1,1,3,4] backup=2 时, 下标0的1已经赋值给了下标1，所以0在modified中
        set<int> modified;
        int curIdx = 0;     // 当前要赋值给其他下标的下标
        while (modified.size() < size) {
            if (modified.count(curIdx)) {
                // 当前下标已经赋值过了
                curIdx ++;
                continue;
            } else {
                int idx = curIdx;
                int backup = nums[idx];
                while (!modified.count(idx)) {
                    int trgIdx = (idx + k) % size;  // nums[idx] 要移动到的下标

                    int backupNew = nums[trgIdx];   // 备份要被替换的下标 nums[_] 替换钱当前的值
                    nums[trgIdx] = backup;
                    backup = backupNew;
                    
                    // 将当前的 idx 加入到 set which 记录已移动到其他地方的数字的下标
                    modified.insert(idx);

                    // cout << idx << ", " << trgIdx << endl;

                    idx = trgIdx;
                }
            }
            curIdx ++;
        }
    }
};


// 思路：用一个 set 记录将 i 赋值给 (i+k) % size 的 i。
//      首先考虑下标 0 开始，赋值给他的目标位 (0+k) % size;
//      然后下一个考虑 (0+k) % size 位，赋值给他的的目标位 (0+2k) % size;
//      再下一个考虑 (0+2k) % size 位 ....
// 注意：
//      1.在每次赋值前需要对 要赋值的目标下标的当前值做好备份，否则目标位下标的值就失去了
//      2.每次将 i 赋值给他的目标下标后，需要将 i 加入到 set 中，然后考虑情况 0, (0+k)%size, (0+2k)%size, .... 直到 (0+nk)%size 在 set 中可以找到停止循环考虑下一个情况，因为当前位置已经赋过值了
//
// 设 N = nums.size()
// 时间复杂度：O(N)
// 空间复杂度：O(N)

// 与 Soln_5 题解中提到的思路不谋而合，Java 实现参考 Soln_5
