-- Link: https://leetcode.com/problems/game-play-analysis-i/?envType=study-plan&id=sql-i

SELECT player_id, event_date AS first_login FROM
(SELECT player_id,event_date,
RANK() OVER (PARTITION BY player_id ORDER BY event_date) my_rank
FROM activity) AS ranked_by_date
WHERE my_rank=1;