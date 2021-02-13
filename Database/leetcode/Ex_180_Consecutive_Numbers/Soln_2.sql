# Write your MySQL query statement below
SELECT DISTINCT Num AS 'ConsecutiveNums' FROM (    
    SELECT Num, COUNT(1) AS 'SerialCount' FROM (
        SELECT Id, Num,
        ROW_NUMBER() OVER(ORDER BY Id) - 
        ROW_NUMBER() OVER(PARTITION BY Num ORDER BY Id) AS SerialNumberSubGroup
        FROM Logs
    ) AS Sub
    GROUP BY Num, SerialNumberSubGroup
    HAVING COUNT(1) >= 3
) AS Result


# 参考：https://leetcode-cn.com/problems/consecutive-numbers/solution/sql-server-jie-fa-by-neilsons/