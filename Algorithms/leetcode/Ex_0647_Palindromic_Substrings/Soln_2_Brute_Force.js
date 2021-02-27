/**
 * @param {string} s
 * @return {number}
 */
const isPalindrome = (s) => {
    let l = 0;
    let r = s.length - 1;
    while (l < r) {
        if (s[l] !== s[r]) {
            return false;
        }
        l += 1;
        r -= 1;
    }    
    return true;
}

var countSubstrings = function(s) {
    let res = 0;
    for (let start = 0; start < s.length; start++) {
        for (let end = start; end < s.length; end++) {
            if (isPalindrome(s.substring(start, end+1))) {
                res += 1;
            }
        }
    }
    return res;
};

// 参考题解：https://leetcode-cn.com/problems/palindromic-substrings/solution/shou-hua-tu-jie-dong-tai-gui-hua-si-lu-by-hyj8/
