#include <string>
#include <map>

using std::string;
using std::map;
using std::to_string;

class Solution_1 {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        // 设置负号
        string res;
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }

        // 转正数，需要用long，因为denominator可能是int的最小数，转成整数时超出int范围
        long posNumerator = (numerator < 0) ? -1 * (long) numerator : numerator;
        long posDenominator = (denominator < 0) ? -1 * (long) denominator : denominator;

        // 计算商的整数部分
        long integer = posNumerator / posDenominator;
        res += to_string(integer);

        // 计算商的余数部分
        long remainder = posNumerator % posDenominator;
        if (remainder == 0) {
            // 没有余数，整除
            return res;
        } else {
            // 没有整除
            res += ".";
            remainder *= 10;

            // 用一个哈希表来保存之前得到过的余数
            // key: remainders that have been appeared
            // val: remainders' position where they appear
            map<long, int> rmds;

            while (remainder && rmds.find(remainder) == rmds.end()) {
                rmds.insert({remainder, res.size()});   // 保存remainder的位置
                long quotient = remainder / posDenominator;
                res += to_string(quotient);
                remainder = (remainder % denominator) * 10;
            }

            // 整除 (remainder = 0) 或者找到了重复的 remainder
            if (rmds.find(remainder) != rmds.end()) {
                // 找到了重复的remainder
                res.insert(rmds[remainder], 1, '(');    // 在第一次出现重复 remainder 前插入左括号
                res += ")";
            } 
            
        }

        return res;
    }
};

// 参考之前账号提交记录
