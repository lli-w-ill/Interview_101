class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        import functools
        @functools.cache
        def helper(i: int, j: int) -> int:
            if i == len(word1) or j == len(word2):
                return len(word1) - i + len(word2) - j;
            if word1[i] == word2[j]:
                return helper(i + 1, j + 1)
            else:
                inserted = helper(i, j + 1)     # 在 word1 的位置 i 插入一个字符
                deleted = helper(i + 1, j)      # 删除 word1 的位置 i 字符
                replaced = helper(i + 1, j + 1) # 替换 word1 的位置 i 字符
                return min(inserted, deleted, replaced) + 1
        return helper(0, 0)

# 解法参考：https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/
# @functools.lru_cache 参考：https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/
"""
Returns the same as lru_cache(maxsize=None), creating a thin wrapper around a dictionary lookup for the function arguments. Because it never needs to evict old values, this is smaller and faster than lru_cache() with a size limit.
"""

