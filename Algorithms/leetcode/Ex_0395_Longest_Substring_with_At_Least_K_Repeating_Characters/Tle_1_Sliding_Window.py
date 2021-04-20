from collections import defaultdict

class Tle_1:
    def longestSubstring(self, s: str, k: int) -> int:
        length = len(s)
        if length < k:
            return 0
        
        longestStr = ''
        for ws in range(k, length + 1): # window size
            # key: char 字符
            # value: char 字符出现的次数
            freq = defaultdict(int)
            
            startPos = 0
            # 初始化 freq
            for i in range(startPos, startPos + ws):
                freq[s[i]] += 1
            
            if self.isValid(freq, k):
                longestStr = s[startPos:startPos + ws]
            
            # 逐渐向右移动 window，每次减少移出去的字符的频率，加上右边新加入的字符的频率
            startPos += 1
            while startPos + ws <= length:
                # print(startPos, ws)
                # 递减左边移出的字符的频率
                freq[s[startPos - 1]] -= 1
                if freq[s[startPos - 1]] == 0:
                    del freq[s[startPos - 1]]

                # 递增右边新增的字符的频率
                freq[s[startPos + ws - 1]] += 1
                
                if self.isValid(freq, k):
                    longestStr = s[startPos:startPos+ws]
                
                startPos += 1

        # print(longestStr)
        return len(longestStr)
    
    def isValid(self, freq: Dict[str, int], k: int) -> bool:
        for (key, value) in freq.items():
            if value < k:
                return False
        return True


# 超出时间限制：30 / 31 个通过测试用例
