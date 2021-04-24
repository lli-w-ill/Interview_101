class Solution_2:
    def partitionLabels(self, S: str) -> List[int]:
        # key: 字符 char
        # value: char 在 S 中最后出现的下标位置
        # 注：后面相同char 的 lastIdx 会覆盖前面赋过的 lastIdx
        dic = {char : lastIdx for lastIdx, char in enumerate(S)}
        # print(dic)

        res = []    # 结果集
        # 第一个字符最后出现的位置
        maxLastIdx = dic[S[0]]  # 注：根据题意这里不用判空 S
        splitLen = 0;     # 记录分割字符串的长度
        length = len(S)

        for i in range(length):
            splitLen += 1
            if dic[S[i]] > maxLastIdx:
                # 说明当前字符最后出现的位置大于当前分割字符串中所有字符的 maxLastIdx，那么更新 maxLastIdx
                maxLastIdx = dic[S[i]]
            if i == maxLastIdx:
                # 当前字符已经到了分割点，在当前字符后面分割，并加入到结果集
                res.append(splitLen)
                # 初始化分割字符串长度
                splitLen = 0 

        return res

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/partition-labels/solution/python-jiu-zhe-quan-guo-zui-cai-you-hua-dai-ma-by-/
