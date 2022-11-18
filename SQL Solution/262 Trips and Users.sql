-- Link: https://leetcode.com/problems/trips-and-users/

select request_at as Day, round(sum(if(status = "cancelled_by_driver" or status = "cancelled_by_client", 1,0 )) / count(id) ,2) as "Cancellation Rate"
from Trips 
where client_id  not in (select users_id from Users  where banned = "Yes") 
and driver_id   not in (select users_id from Users  where banned = "Yes")
and request_at between "2013-10-01" and "2013-10-03"
group by request_at 
order by 1