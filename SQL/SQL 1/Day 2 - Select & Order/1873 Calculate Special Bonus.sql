-- Link: https://leetcode.com/problems/calculate-special-bonus/?envType=study-plan&id=sql-i

select employee_id,
IF((employee_id % 2) != 0 AND name NOT like 'M%', salary, 0) as 'bonus'
from Employees
order by employee_id;