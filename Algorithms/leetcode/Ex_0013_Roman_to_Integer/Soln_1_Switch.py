class Solution_1:
    def romanToInt(self, s: str) -> int:
        length = len(s)
        idx = 0
        res = 0
        while idx < length:
            if s[idx] == 'I':
                # 看是否能与其后的一个字符组合
                if idx + 1 < length:
                    if s[idx + 1] == 'V':
                        res += 4
                        idx += 2
                    elif s[idx + 1] == 'X':
                        res += 9
                        idx += 2
                    else:
                        res += 1
                        idx += 1
                else:
                    res += 1
                    idx += 1
            elif s[idx] == 'X':
                # 看是否能与其后的一个字符组合
                if idx + 1 < length:
                    if s[idx + 1] == 'L':
                        res += 40
                        idx += 2
                    elif s[idx + 1] == 'C':
                        res += 90
                        idx += 2
                    else:
                        res += 10
                        idx += 1
                else:
                    res += 10
                    idx += 1
            elif s[idx] == 'C':
                # 看是否能与其后的一个字符组合
                if idx + 1 < length:
                    if s[idx + 1] == 'D':
                        res += 400
                        idx += 2
                    elif s[idx + 1] == 'M':
                        res += 900
                        idx += 2
                    else:
                        res += 100
                        idx += 1
                else:
                    res += 100
                    idx += 1
            elif s[idx] == 'V':
                res += 5
                idx += 1
            elif s[idx] == 'L':
                res += 50
                idx += 1
            elif s[idx] == 'D':
                res += 500
                idx += 1
            elif s[idx] == 'M':
                res += 1000
                idx += 1
        return res