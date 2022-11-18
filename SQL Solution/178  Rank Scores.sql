-- Link: https://leetcode.com/problems/rank-scores/

SELECT score, dense_rank() OVER(ORDER BY score DESC) as "rank"
FROM Scores