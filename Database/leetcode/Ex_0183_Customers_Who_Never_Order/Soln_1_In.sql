-- Write your MySQL query statement below
SELECT C1.Name AS 'Customers'
FROM Customers C1
WHERE C1.Id NOT IN (
    SELECT CustomerId
    FROM Orders
);