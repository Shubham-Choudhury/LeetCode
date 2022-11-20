-- Link: https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/

select actor_id, director_id 
from(
select actor_id,director_id, 
count(timestamp) as cooperated 
from ActorDirector 
group by actor_id,director_id) 
table1
where cooperated>=3;