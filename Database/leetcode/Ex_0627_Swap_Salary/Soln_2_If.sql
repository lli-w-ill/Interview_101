-- Write your MySQL query statement below
UPDATE salary
SET 
    sex = IF (sex = 'm', 'f', 'm')
;

-- IF: https://www.w3schools.com/sql/func_mysql_if.asp
