-- Write your MySQL query statement below
SELECT D.Name AS 'Department', E.Name AS 'Employee', E.Salary
FROM Employee E, Department D, (
    SELECT DepartmentId, MAX(Salary) AS 'MaxSalary' FROM Employee
    GROUP BY DepartmentId
) AS TEMP
WHERE E.Salary = TEMP.MaxSalary
AND E.DepartmentId = TEMP.DepartmentId
AND D.Id = TEMP.DepartmentId;