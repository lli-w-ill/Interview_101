/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {

    if (strs.length == 0) {
        return "";
    }

    let common = strs[0];
    for (let i = 1; i < strs.length; i++) {
        let j;
        for (j = 0; j < common.length && j < strs[i].length; j++) {
            if (common[j] != strs[i][j]) {
                break;
            }
        }
        common = common.substring(0, j);
    }

    return common;
};
