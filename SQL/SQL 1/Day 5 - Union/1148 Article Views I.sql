-- Link: https://leetcode.com/problems/article-views-i/?envType=study-plan&id=sql-i

SELECT DISTINCT author_id AS id FROM Views 
where author_id = viewer_id 
ORDER BY id
