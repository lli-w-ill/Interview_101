package Algorithms.leetcode.Ex_0168_Excel_Sheet_Column_Title;

class Solution_2 {
    public String convertToTitle(int columnNumber) {
        StringBuffer buffer = new StringBuffer();

        while (columnNumber != 0) {
            int remainder = (columnNumber % 26 == 0) ? 26 : columnNumber % 26;  // 起点是 1 而不是 0
            char cur = (char)('A' - 1 + remainder);
            buffer.insert(0, cur);  // 注意这里是在头部插入

            columnNumber = (columnNumber - remainder) / 26;
        }

        return buffer.toString();

    }
}

// 参考题解：https://leetcode-cn.com/problems/excel-sheet-column-title/solution/bei-jian-dan-ti-qia-liao-na-yao-jiu-tu-l-bkqb/
