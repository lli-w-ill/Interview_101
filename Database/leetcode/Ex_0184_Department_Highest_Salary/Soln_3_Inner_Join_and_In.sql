-- Write your MySQL query statement below
SELECT 
    Department.Name AS 'Department', 
    Employee.Name AS 'Employee',
    Salary
FROM Employee
INNER JOIN Department
ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId, Salary) IN (
        SELECT DepartmentId, MAX(Salary)
        FROM Employee
        GROUP BY DepartmentId
    )
;

-- 参考题解：https://leetcode-cn.com/problems/department-highest-salary/solution/bu-men-gong-zi-zui-gao-de-yuan-gong-by-leetcode/
