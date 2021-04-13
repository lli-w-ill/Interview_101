#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution_3 {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        if (nums.empty()) {
            return ans;
        }

        // convert all numbers to strings
        vector<string> asStrs;
        asStrs.reserve(nums.size());
        for (const int &i : nums) {
            asStrs.push_back(std::to_string(i));
        }

        // declare the custom comparable rules
        struct {
            bool operator()(const string &a, const string &b) {
                string order1 = a + b;
                string order2 = b + a;
                int result = order1.compare(order2);
                return result > 0;
            }
        } customGreaterThan;
        std::sort(asStrs.begin(), asStrs.end(), customGreaterThan);

        if (asStrs[0] == "0") {
            // if the largest number is 0, then return "0" directly
            return "0";
        }

        // build largest number from sorted string array
        for (const string &numAsStr : asStrs) {
            // cout << numAsStr << endl;
            ans += numAsStr;
        }

        return ans;
    }
};

// 参考之前账号提交记录
