-- Write your MySQL query statement below
SELECT TEMP.Name AS 'Department', E.Name AS 'Employee', E.Salary 
FROM (
    SELECT D.Id, D.Name, MAX(E.Salary) AS 'Salary'
    FROM Employee E
    LEFT JOIN Department D
    ON E.DepartmentId = D.Id
    GROUP BY D.Name
) AS TEMP, Employee E
WHERE E.Salary = TEMP.Salary
AND E.DepartmentId = TEMP.Id;
