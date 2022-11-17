-- Link: https://leetcode.com/problems/find-followers-count/?envType=study-plan&id=sql-i

Select user_id , Count(Distinct follower_id) as followers_count 
from Followers 
group by user_id