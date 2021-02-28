from collections import Counter

class Solution_1:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        counter_p = Counter(p)
        if len(s) < len(p):
            return []
        
        res = []
        
        # 对第一次判断特殊处理
        counter_s_substring = Counter(s[:len(p)])
        if counter_p == counter_s_substring:
            res.append(0)
        
        for i in range(1, len(s) - len(p) + 1):
            # 递减／移除上一个窗口的第一个字母
            counter_s_substring[s[i-1]] -= 1
            if counter_s_substring[s[i-1]] == 0:
                del counter_s_substring[s[i-1]]
            
            # 递增新窗口的尾元素
            newChar = s[i+len(p)-1] # 新进窗口的字符
            if s[i+len(p)-1] not in counter_s_substring:
                counter_s_substring[newChar] = 1
            else:
                counter_s_substring[newChar] += 1

            if counter_s_substring == counter_p:
                res.append(i)
        
        return res
