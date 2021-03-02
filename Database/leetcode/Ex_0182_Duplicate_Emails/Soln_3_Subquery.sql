-- Write your MySQL query statement below
SELECT Email
FROM (
    SELECT Email, COUNT(Email) AS 'Freq'
    FROM PERSON
    GROUP BY Email
) AS TEMP   # 临时表明不能用''扩起来
WHERE TEMP.Freq > 1;