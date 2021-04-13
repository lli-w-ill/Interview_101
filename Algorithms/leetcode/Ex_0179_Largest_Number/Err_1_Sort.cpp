#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

class Err_1 {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end(), [=](int a, int b) {
            // 传入倒序的 a，b，因为要从最高位开始比较
            return compare(reverse(a), reverse(b));
        });

        string res;
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }

        return res;
    }

private:
    // 如果让 a 排在 b 的前面，return true
    // 如果让 a 排在 b 的后面，return false
    bool compare(int a, int b) {
        // 记住 a，b 是 nums 中原数字的倒序
        int truncateA = 0;  // 记住 a 被除去的部分  
        int truncateB = 0;  // 记住 b 被出去的部分
        while (a > 0 && b > 0) {
            if (a % 10 > b % 10) {
                // 排序后，让 a 排在 b 前面
                // e.g. a = 36, b = 35
                //      3635 > 3536
                return true;
            } else if (a % 10 < b % 10) {
                // 排序后，让 a 排在 b 后面
                return false;
            }
            truncateA = truncateA * 10 + a % 10;
            truncateB = truncateB * 10 + b % 10;
            a /= 10;
            b /= 10;
        }
        if (a > 0) {
            // 比较 a 与 a被除去的部分
            return compare(truncateA, a);
        } 
        if (b > 0) {
            // 比较 b 与 b被除去的部分
            return compare(truncateB, b);
        }
        // 说明 a == b，任意顺序都可以
        return true;
    }

    int reverse(int x) {
        int reversedX = 0;
        while (x > 0) {
            reversedX = reversedX * 10 + x % 10;
            x /= 10;
        }
        return reversedX;
    }
};

// 依然存在问题：
// 1. 可能是由前导 0 导致的，因为 10 reverse后需要时 01，然而如果用 int 类型做 reversedX，就会变成 1，前导0 就不见了
//
// 测试用例：[10,2,9,39,17]
// 正确结果："93921710"
// 当前输出："93921017"
