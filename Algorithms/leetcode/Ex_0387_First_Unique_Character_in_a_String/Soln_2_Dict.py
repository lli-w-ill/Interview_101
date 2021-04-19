class Solution_2:
    def firstUniqChar(self, s: str) -> int:
        # key: 字符
        # value: 其出现的下标（如果是重复的字符，则设为 len(s)）
        uniqCharMap = {}
        length = len(s)
        if length == 0:
            return -1

        for i in range(length):
            ch = s[i]
            if ch not in uniqCharMap:
                uniqCharMap[ch] = i
            else:
                uniqCharMap[ch] = length
            
        # 扫描一遍 charMap，返回最小的 value
        minKey = ''     # 这里没有用到，仅记录一下
        minVal = length + 1
        for (key, value) in uniqCharMap.items():
            if value < minVal:
                minKey = key
                minVal = value
        
        return minVal if minVal < length else -1

