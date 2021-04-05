class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # key: (#, #, #, ..., #) 从前往后，每个#以此表示: a, b, c, d, ... 出现的次数
        # value: a list of anagrams
        res = collections.defaultdict(list)
        for s in strs:
            charFreq = [0] * 26
            for char in s:
                charFreq[ord(char) - ord('a')] += 1
            res[tuple(charFreq)].append(s)
        return [res[key] for key in res.keys()]

# a-z每个字符出现的频率作为key
