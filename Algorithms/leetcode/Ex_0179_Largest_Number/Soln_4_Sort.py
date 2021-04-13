class Solution_4:
    def largestNumber(self, nums: List[int]) -> str:
        # 将 nums 中的数字都变成 str
        strs = map(str, nums)

        def compare(a: str, b: str) -> int:
            if a + b == b + a:
                return 0
            elif a + b > b + a:     # 注意这里是字符串比较（从第一位逐个字符比较）
                return 1
            else:
                return -1
        
        strs = sorted(strs, key=functools.cmp_to_key(compare), reverse=True)

        # for s in strs:
        #     print(s)
        
        return ''.join(strs) if strs[0] != '0' else '0'

# 参考题解：https://leetcode-cn.com/problems/largest-number/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-vn86e/
# functools.cmp_to_key 文档: https://docs.python.org/3/library/functools.html
