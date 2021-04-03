-- Write your MySQL query statement below
SELECT W1.Id
FROM Weather W1, Weather W2
WHERE 
    W2.recordDate = SUBDATE(W1.recordDate, 1)
AND 
    W1.Temperature > W2.Temperature
;