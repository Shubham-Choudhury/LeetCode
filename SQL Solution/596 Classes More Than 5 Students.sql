-- Link: https://leetcode.com/problems/classes-more-than-5-students/

select distinct class from Courses
group by class
having count(class) > 4;