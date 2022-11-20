-- Link: https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/

SELECT customer_id, COUNT(v.visit_id) as count_no_trans 
FROM Visits v
LEFT JOIN Transactions t ON v.visit_id = t.visit_id
WHERE transaction_id IS NULL
GROUP BY customer_id