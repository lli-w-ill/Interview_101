-- Write your MySQL query statement below
UPDATE salary
SET 
    sex = CASE sex
        WHEN 'm' THEN 'f'
        WHEN 'f' THEN 'm'
        ELSE sex    -- 保持原值如果非'm'非'f'
    END
;
