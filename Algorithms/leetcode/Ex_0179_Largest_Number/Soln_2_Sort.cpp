#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pow;

class Solution_2 {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        if (nums.empty()) {
            return ans;
        }

        // deal with all 0s scenario
        bool allZeroes = true;
        for (const int &i : nums) {
            if (i != 0) {
                allZeroes = false;
                break;
            }
        }
        if (allZeroes) {
            return "0";
        }

        // declare the custom comparable rules
        struct {
            bool operator()(int n1, int n2) const {
                string s1 = std::to_string(n1);
                string s2 = std::to_string(n2);
                auto bitsN1 = static_cast<int> (s1.size());
                auto bitsN2 = static_cast<int> (s2.size());
                long feedN1 = static_cast<long> (pow(10, bitsN1));
                long feedN2 = static_cast<long> (pow(10, bitsN2));

                return n1 * feedN2 + n2 >= n2 * feedN1 + n1;
            }
        } customGreaterThan;
        std::sort(nums.begin(), nums.end(), customGreaterThan);

        for (const int &i : nums) {
            // cout << i << endl;
            ans += std::to_string(i);
        }

        return ans;
    }
};

// 参考之前账号提交记录
