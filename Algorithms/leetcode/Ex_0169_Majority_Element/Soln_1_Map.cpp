#include <map>
#include <vector>

using std::map;
using std::vector;

class Solution_1 {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        }
        
        // 对每个出现在 nums 中的数字累计出现的频率
        map<int, int> freq;
        for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++) {
            if (freq.find(*it) != freq.end()) {
                freq[*it] = freq[*it] + 1;
            } else {
                freq.insert(std::pair<int, int> (*it, 1));
            }
        }

        // 遍历 map，找到出现次数 > n//2 的元素
        for (map<int, int>::const_iterator it = freq.begin(); it != freq.end(); it++) {
            if (it->second > n / 2) {
                return it->first;
            }
        }
        return 0;
    }
};
