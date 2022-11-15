-- Link: https://leetcode.com/problems/swap-salary/?envType=study-plan&id=sql-i

UPDATE salary SET sex =
CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;