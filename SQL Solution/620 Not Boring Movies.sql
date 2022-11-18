-- Link: https://leetcode.com/problems/not-boring-movies/

SELECT * FROM Cinema
WHERE NOT description='boring' AND  ID%2
ORDER BY rating DESC
