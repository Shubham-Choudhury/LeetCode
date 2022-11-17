-- Link: https://leetcode.com/problems/capital-gainloss/?envType=study-plan&id=sql-i

SELECT stock_name, SUM(
    CASE
        WHEN operation = 'Buy' THEN -price
        ELSE price
    END
) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name