#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution_1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();

        // key: nums1 中出现的数字
        // value: key 在 nums1 中出现的频率
        map<int, int> freq1;

        for (const int &i : nums1) {
            if (freq1.count(i)) {
                freq1[i] ++;
            } else {
                freq1[i] = 1;
            }
        }

        vector<int> res;
        for (const int &j : nums2) {
            if (freq1.count(j) && freq1[j] > 0) {
                res.push_back(j);
                freq1[j] --;
            }
        }

        return res;
    }
};

// 如果 nums1 的大小比 nums2 小很多，那么这种方法适用
