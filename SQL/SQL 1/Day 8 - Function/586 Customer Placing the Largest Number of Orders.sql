-- Link: https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/?envType=study-plan&id=sql-i

with cte as(select customer_number, count(order_number) as count1 from Orders   group by customer_number order by count1 desc)
select customer_number from cte limit 1
