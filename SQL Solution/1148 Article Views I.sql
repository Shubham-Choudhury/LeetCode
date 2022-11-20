-- Link: https://leetcode.com/problems/article-views-i/

SELECT DISTINCT author_id AS id FROM Views 
where author_id = viewer_id 
ORDER BY id
