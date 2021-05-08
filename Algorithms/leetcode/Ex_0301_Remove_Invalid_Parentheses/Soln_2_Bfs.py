class Solution_2:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def isValid(s: str) -> bool:
            # 检查 s 是否是一个合法的括号串
            cnt = 0
            for char in s:
                if char == '(':
                    cnt += 1
                elif char == ')':
                    cnt -= 1
                if cnt < 0:
                    return False
            return cnt == 0
        
        # bfs
        level = set()
        level.add(s)
        while True:
            # 删除不合法的括号串，将当前层所有合法的括号串晒出来
            valid = list(filter(isValid, level))
            if valid:
                # 说明当前已经有结果了，直接返回即可
                # 还有一个问题：怎么证明valid中所有括号串就是最少删除字符次数的呢？
                # 回答：因为根据下面 bfs 循环，每次都只删一个字符，而且逐层由上向下遍历，所以如果在当前层找到了合法的括号串，那么一定是删除字符最少的
                return valid
            # 将下一层的所有括号串加入到level
            next_level = set()
            for string in level:
                for i in range(len(string)):
                    if string[i] in ('(', ')'):
                        next_level.add(string[:i] + string[i+1:])   # 删除当前括号，将剩下的括号串加入到level
            level = next_level

# 参考题解：https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/bfsjian-dan-er-you-xiang-xi-de-pythonjiang-jie-by-/
# 时间复杂度：应该是指数级别的，因为最坏情况下（原s中全是左右括号，没有无关字符） bfs 数的第一层是 s，第一层->第二层是 n-1 叉树，第二层的nodes -> 第三层是 n-2 叉树，...，最后展开应该是一共有 1 + 1 * (n-1) + (n-1) * (n-2) + (n-2) * (n-3) + ...
