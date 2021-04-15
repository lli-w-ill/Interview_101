#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution_1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ump;
        for (const int &i : nums) {
            if (ump.count(i)) {
                return true;
            } else {
                ump.insert(i);
            }
        }
        return false;
    }
};
