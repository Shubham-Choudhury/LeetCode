-- Link: https://leetcode.com/problems/bank-account-summary-ii/

SELECT u.name AS name , SUM(t.amount) AS balance
FROM Users AS u LEFT JOIN Transactions AS t 
ON u.account=t.account
GROUP BY name HAVING balance>10000;