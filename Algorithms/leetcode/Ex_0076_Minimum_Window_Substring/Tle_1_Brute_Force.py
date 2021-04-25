class Tle_1:
    def minWindow(self, s: str, t: str) -> str:
        import copy
        from collections import defaultdict
        # brute force想法，在s中从前往后依次循环
        #   如果s[i]在t中，则内层循环从i开始往后，直到 涵盖t中所有字符 或者 到达s结尾
        #   如果s[i]不在t中，则继续向后循环
        dicT = defaultdict(int)   # 保存t中出现的所有字符对应其出现的频率
        minStr = ""     # 最短子串
        minLen = 0      # 最短子串的长度
        for char in t:
            dicT[char] += 1
        # 开始循环
        for i in range(len(s) - len(t) + 1):
            if dicT[s[i]] > 0:
                # 新建一份拷贝，供内层循环使用
                dicTCopy = dicT.copy()
                cnt = 0     # 计数当前子串已经涵盖了多少个t中的字符
                minStrTemp = ""
                # 对于字符s[i]，t中还有没有匹配到的字符
                # 开始内层循环
                for j in range(i, len(s)):
                    if dicTCopy[s[j]] > 0:
                        dicTCopy[s[j]] -= 1
                        cnt += 1
                    minStrTemp += s[j]
                    if cnt == len(t):
                        break
                if cnt == len(t) and (minLen == 0 or len(minStrTemp) < minLen):
                    # 更新全局最小子串
                    minLen = len(minStrTemp)
                    minStr = minStrTemp
        return minStr
