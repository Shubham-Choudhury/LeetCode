-- Link: https://leetcode.com/problems/duplicate-emails/?envType=study-plan&id=sql-i

SELECT email from Person
group by email
having count(email) > 1;