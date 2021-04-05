class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # key: (#, #, #, ..., #) 表示同一组anagrams所使用的所有char从a-z排过序的tuple
        # value: a list of anagrams
        res = collections.defaultdict(list)
        for s in strs:
            key = sorted([ch for ch in s])
            res[tuple(key)].append(s)
        return [res[key] for key in res.keys()]

# 同一组字母异位词所使用的所有字符按照从a-z排序过的tuple作为key
# 相较于Soln_1，这种解法有一个缺点，就是Soln_1的key是定长的，而这个解法key是不定长的，而且key一定要排序，所以如果strs中字符都很长，这个解法不如Soln_1
