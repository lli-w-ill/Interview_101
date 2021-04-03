class Solution_1:
    def myAtoi(self, s: str) -> int:
        if not s or len(s) == 0:
            return 0
        
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -2 ** 31

        # 丢弃前导空格
        idx = 0
        while idx < len(s) and s[idx] == ' ':
            idx += 1

        # 如果已经读到结尾则直接返回0
        if idx == len(s):
            return 0

        # 尝试读入正负号
        sign = '?'
        if s[idx] == '+' or s[idx] == '-':
            sign = s[idx]
            idx += 1
        
        # 逐个读到下一个非数字字符或s结尾
        resStr = ''
        while idx < len(s) and s[idx].isnumeric():
            if s[idx] == '0' and resStr == '':
                idx += 1
                continue
            
            resStr += s[idx]
            idx += 1
        
        # 如果依旧结果为空，则直接返回0
        if resStr == '':
            return 0
        
        # 转换为int
        if sign == '-':
            res = -int(resStr)
        else:
            res = int(resStr)

        # 检查越界
        if res < INT_MIN:
            res = INT_MIN
        elif res > INT_MAX:
            res = INT_MAX
        
        return res
    

# 这个方法有个潜在问题：
# 因为 转换为int 时是强制转换的，python 对 int 没有限制范围所以才没事
# 如果用 C++／Java 实现就会有问题
