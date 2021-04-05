/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */

let memo = new Map();

var isMatch = function(s, p) {
    // base cases
    if (s === "" && p === "")
        return true;
    else if (s !== "" && p === "")
        return false;
    
    // 查找备忘录
    if (memo.has((s, p))) {
        return memo[(s, p)];
    }
    
    if (s !== "" && p !== "") {
        if (s[0] === p[0] || p[0] === '?')
            memo[(s, p)] = isMatch(s.substring(1), p.substring(1));
        else if (p[0] == '*')
            // 1.匹配空字符
            // 2.匹配单个字符
            // 3.匹配多个字符
            memo[(s, p)] = isMatch(s, p.substring(1)) || isMatch(s.substring(1), p.substring(1)) || isMatch(s.substring(1), p);
        else if (s[0] != p[0])
            memo[(s, p)] = false;
    } else if (s === "" && p !== "") {
        if (p[0] === '*') {
            // 1.匹配空字符
            memo[(s, p)] = isMatch(s, p.substring(1));
        } else {
            memo[(s, p)] = false;
        }
    }
    
    return memo[(s, p)];
};
