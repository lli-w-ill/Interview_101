package Algorithms.leetcode.Ex_0166_Fraction_to_Recurring_Decimal;

import java.util.Map;
import java.util.HashMap;

class Solution_2 {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        StringBuilder fraction = new StringBuilder();
        // 检查负号
        if (numerator < 0 ^ denominator < 0) {
            fraction.append("-");
        }

        // 将除数，被除数转成 long，因为int的负极限在转正数时会溢出
        long divident = Math.abs(Long.valueOf(numerator));  // 被除数
        long divisor = Math.abs(Long.valueOf(denominator)); // 除数

        // 添加整数部分
        fraction.append(String.valueOf(divident / divisor));

        long remainder = divident % divisor;
        if (remainder == 0) {
            return fraction.toString();
        }

        // 添加小数部分
        fraction.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (remainder != 0) {
            if (map.containsKey(remainder)) {
                // 余数重复了
                fraction.insert(map.get(remainder), "(");
                fraction.append(")");
                break;
            }
            map.put(remainder, fraction.length());
            remainder *= 10;
            fraction.append(String.valueOf(remainder / divisor));
            remainder %= divisor;
        }

        return fraction.toString();
    }
}

// 参考题解：https://leetcode-cn.com/problems/fraction-to-recurring-decimal/solution/fen-shu-dao-xiao-shu-by-leetcode/
