/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    let map = new Map();
    nums.forEach(num => map.set(num, true));
    var i;
    var res = [];
    for (i = 1; i <= nums.length; i++) {
        if (!map.has(i)) {
            res.push(i);
        }
    }
    return res;
};
