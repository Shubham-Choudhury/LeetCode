-- Link: https://leetcode.com/problems/duplicate-emails/

SELECT email from Person
group by email
having count(email) > 1;