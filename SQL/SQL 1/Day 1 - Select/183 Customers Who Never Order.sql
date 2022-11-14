-- Link: https://leetcode.com/problems/customers-who-never-order/?envType=study-plan&id=sql-i

select name as Customers
from Customers c
where id not in (select customerId from Orders);