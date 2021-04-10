class Solution_1:
    def generateAllSplits(self, s: str, curSplit: List[str], allSplits: Set[List[str]]) -> None:
        if s is None or len(s) == 0:
            allSplits.add(tuple(curSplit))
            return

        for length in range(1, len(s) + 1): # 子串长度
            curSplit.append(s[:length])
            self.generateAllSplits(s[length:], curSplit, allSplits)
            curSplit.pop()  # 回溯

    def partition(self, s: str) -> List[List[str]]:
        allSplits = set()
        self.generateAllSplits(s, [], allSplits)

        res = []
        for split in allSplits:
            allPalindrome = True
            for s in split: 
                if (not self.isPalindrome(s)):
                    allPalindrome = False
            if allPalindrome:
                res.append(split)
                
        return res

    def isPalindrome(self, s: str) -> bool:
        if len(s) == 0 or len(s) == 1:
            return True
        return (s[0] == s[-1]) and self.isPalindrome(s[1:len(s)-1])


# 思路：从 s 的首到尾生成所有可能的分割，举例：
# s = "aab"
# 所有的分割有 ["a", "a", "b"], ["aa", "b"], ["a", "ab"], ["aab"]
# 然后逐个判断每个可能的分割中的每个字符，看是不是里面都是回文串，如果是，则加入到结果集中
