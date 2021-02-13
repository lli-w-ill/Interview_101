# Write your MySQL query statement below
SELECT Score, DENSE_RANK() OVER (
    ORDER BY Score DESC
) AS 'Rank' FROM Scores

# 参考：https://leetcode-cn.com/problems/rank-scores/solution/zi-jie-ti-ku-178-zhong-deng-sqlfen-shu-pai-ming-1s/