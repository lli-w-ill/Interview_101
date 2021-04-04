/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    // 特判
    if (needle == "") {
        return 0;
    }
    
    for (let i = 0; i <= haystack.length - needle.length; i++) {
        if (haystack[i] == needle[0] && haystack.substring(i, i + needle.length) == needle) {
            return i;
        }
    }
    return -1;
};
