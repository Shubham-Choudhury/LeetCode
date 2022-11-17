-- Link: https://leetcode.com/problems/sales-person/?envType=study-plan&id=sql-i

select name from salesperson
where sales_id not in (select sales_id
from orders o
left join company c
on o.com_id = c.com_id
where c.name LIKE 'RED')