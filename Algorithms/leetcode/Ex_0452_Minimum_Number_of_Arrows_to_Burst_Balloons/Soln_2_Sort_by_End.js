/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    // 按照 end 升序排序
    points.sort((a, b) => a[1] - b[1]);

    let arrows = 0;
    let i = 0;
    while (i < points.length) {
        const end = points[i][1];
        i ++;

        // 比较其后面区间的 start 是否在当前合并区间的 end 之前或相等
        while (i < points.length && points[i][0] <= end) {
            i ++;
        }

        arrows ++;
    }

    return arrows
};

// 参考题解（推荐）：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/solution/tu-jie-tan-tao-wei-shi-yao-yao-an-qu-jian-de-you-d/

