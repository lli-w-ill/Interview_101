class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import defaultdict
        left, right = 0, -1
        res = (0, float('inf'))     # 记录最小子串左边界和右边界（左右均为闭区间）
        # need 记录当前窗口（s[left ... right]）下，还需要涵盖的每个t中字符数量
        # 如果某个字符对应的value是负数，例如need = {'A': -2, 'C': 1}，就代表当前窗口中有2个多余的A，同时还需要1个C
        need = defaultdict(int)
        for char in t:
            need[char] += 1
        # needCnt 记录当前窗口下，还需要涵盖字符数量的总数
        needCnt = len(t)
        for right, char in enumerate(s):
            if need[char] > 0:
                needCnt -= 1
            need[char] -= 1     # 这个不放在if里面的原因是：要记录多余出来的字符
            if needCnt == 0:
                # 步骤1: 当前滑动窗口 s[left ... right] 已经包含了t的所有字符
                # 开始步骤2: 从左缩小窗口宽度
                while left < right and need[s[left]] < 0:
                    need[s[left]] += 1
                    left += 1
                # 此时不能再让left右移了，因为在右移就覆盖不了t的所有字符了
                # 判断是否找到了更小的窗口（当前窗口宽度res[1]-res[0]+1）
                if res[1] - res[0] + 1 > right - left + 1:
                    res = (left, right)
                # 步骤3: 让left再右移一位，此时窗口就不满足了，重复步骤1
                need[s[left]] += 1
                needCnt += 1
                left += 1
        return "" if res[1] == float('inf') else s[res[0]:res[1]+1]


# 解法参考：https://leetcode-cn.com/problems/minimum-window-substring/solution/tong-su-qie-xiang-xi-de-miao-shu-hua-dong-chuang-k/
# 解法步骤：
# 步骤1: 定义两个指针left=0, right=0，增大窗口宽度：让right不断向右走，直到包含t中所有元素或者到达s末尾
# 步骤2: 开始从左缩小窗口宽度，扔掉不必要的字符，直到left碰到一个必须包含的字符（即如果扔掉s[left]，就不能保证s[left ... right]是包含t的一个子串了
# 步骤3: 让left+1，此时s[left...right]已经不是包含t的子串了，继续从右端增大窗口宽度，回到步骤1

