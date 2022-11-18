-- Link: https://leetcode.com/problems/human-traffic-of-stadium/

select s.id, s.visit_date, s.people
from Stadium s
left join Stadium ls on ls.people >= 100 and ls.id = s.id - 1
left join Stadium rs on rs.people >= 100 and rs.id = s.id + 1
left join Stadium lls on lls.people >= 100 and lls.id = s.id - 2
left join Stadium rrs on rrs.people >= 100 and rrs.id = s.id + 2
where s.people >= 100 and (
    (ls.id is not null and rs.id is not null) 
    or
    (ls.id is not null and lls.id is not null)
    or
    (rs.id is not null and rrs.id is not null)
)