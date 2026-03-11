# Write your MySQL query statement below
(
select u.name as results 
from MovieRating m join users u 
on m.user_id=u.user_id
group by u.user_id 
order by count(*) desc ,u.name asc limit 1
)
union all
(
select m.title as results
from MovieRating r join Movies m 
on m.movie_id=r.movie_id
where r.created_at>='2020-02-01' and r.created_at<='2020-02-29' 
group by m.title,m.movie_id 
order by avg(r.rating) desc ,m.title asc limit 1
)