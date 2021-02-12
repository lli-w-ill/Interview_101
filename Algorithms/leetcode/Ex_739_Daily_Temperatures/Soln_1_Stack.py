class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ans = []
        stack = []  # 保存下标
        if not T:
            return ans
        ans = [0] * len(T)
        for i in range(len(T)):
            while stack and T[i] > T[stack[-1]]:
                idx = stack.pop()
                ans[idx] = i - idx
            stack.append(i)
        return ans
