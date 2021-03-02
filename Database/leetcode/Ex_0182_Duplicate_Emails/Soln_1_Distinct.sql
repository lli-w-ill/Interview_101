# Write your MySQL query statement below
SELECT DISTINCT(P1.Email)
FROM PERSON P1, PERSON P2
WHERE P1.Id != P2.Id
AND P1.Email = P2.Email;