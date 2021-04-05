/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    // base cases
    if (s === "" && p === "")
        return true;
    else if (s !== "" && p === "")
        return false;
    
    if (s !== "" && p !== "") {
        if (s[0] === p[0] || p[0] === '?')
            return isMatch(s.substring(1), p.substring(1));
        else if (p[0] == '*')
            // 1.匹配空字符
            // 2.匹配单个字符
            // 3.匹配多个字符
            return isMatch(s, p.substring(1)) || isMatch(s.substring(1), p.substring(1)) || isMatch(s.substring(1), p);
        else if (s[0] != p[0])
            return false;
    } else if (s === "" && p !== "") {
        if (p[0] === '*') {
            // 1.匹配空字符
            return isMatch(s, p.substring(1));
        } else {
            return false;
        }
    }
    
};
