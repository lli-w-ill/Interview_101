-- Write your MySQL query statement below
SELECT C1.Name AS 'Customers'
FROM Customers C1
WHERE NOT EXISTS (
    SELECT O1.CustomerId
    FROM Orders O1
    WHERE C1.Id = O1.CustomerId
);