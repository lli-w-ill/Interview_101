class Solution_1:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        res = ["" for _ in range(numRows)]
        i = 0
        flag = -1
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1:
                # 转向填充方向
                flag = -flag
            i += flag
        return "".join(res)
            
# 参考题解（强烈推荐）：https://leetcode-cn.com/problems/zigzag-conversion/solution/zzi-xing-bian-huan-by-jyd/
