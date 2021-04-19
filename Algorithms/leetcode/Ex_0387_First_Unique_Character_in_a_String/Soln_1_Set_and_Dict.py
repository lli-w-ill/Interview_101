class Solution_1:
    def firstUniqChar(self, s: str) -> int:
        # 特判
        if not s:
            return -1
        length = len(s)
        if length == 0:
            return -1
        if length == 1:
            return 0

        # key: 不重复的字符
        # value: 其出现的下标
        uniqCharMap = {}
        duplicateCharSet = set()

        for i in range(length):
            ch = s[i]
            if ch not in uniqCharMap:
                uniqCharMap[ch] = i
            else:
                # 从 charMap 中删除 ch 这个 key 项
                duplicateCharSet.add(ch)
        
        # 将重复出现的字符从 uniqCharMap 中删除
        for ch in duplicateCharSet:
            del uniqCharMap[ch]
        
        # 扫描一遍 charMap，返回最小的 value
        # 判断 charMap 当前是否为空
        if len(uniqCharMap) == 0:
            return -1
        minKey = ''     # 这里没有用到，仅记录一下
        minVal = float('inf')
        for (key, value) in uniqCharMap.items():
            if value < minVal:
                minKey = key
                minVal = value
        
        return minVal
