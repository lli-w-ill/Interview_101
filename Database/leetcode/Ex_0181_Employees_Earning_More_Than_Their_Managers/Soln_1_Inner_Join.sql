# Write your MySQL query statement below
SELECT E1.Name AS 'Employee'
FROM EMPLOYEE E1
INNER JOIN EMPLOYEE E2
ON E1.ManagerID = E2.Id
AND E1.Salary > E2.Salary;