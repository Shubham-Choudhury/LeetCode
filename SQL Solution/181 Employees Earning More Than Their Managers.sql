-- Link: https://leetcode.com/problems/employees-earning-more-than-their-managers/

select name as Employee 
from employee emp
where salary > (select salary from Employee where id=emp.managerId)