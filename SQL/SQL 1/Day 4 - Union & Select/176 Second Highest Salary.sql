-- Link: https://leetcode.com/problems/second-highest-salary/?envType=study-plan&id=sql-i

select max(salary) as SecondHighestSalary from Employee
where salary not in (select max(salary) from Employee)