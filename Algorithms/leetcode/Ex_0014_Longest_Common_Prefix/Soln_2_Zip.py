class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""
        for temp in zip(*strs):
            temp_set = set(temp)
            # print(temp, temp_set)
            if len(temp_set) == 1:
                res += temp[0]
            else:
                break
        return res

# 参考题解：https://leetcode-cn.com/problems/longest-common-prefix/solution/duo-chong-si-lu-qiu-jie-by-powcai-2/
# * 操作：https://stackoverflow.com/questions/29139350/difference-between-ziplist-and-ziplist
