class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        phone = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        queue = ['']
        for d in digits:
            size = len(queue)
            for _ in range(size):
                temp = queue.pop(0)
                for letter in phone[ord(d) - ord('2')]:
                    queue.append(temp + letter)
        return queue


# 参考：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/hui-su-dui-lie-tu-jie-by-ml-zimingmeng/
