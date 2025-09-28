# Write your MySQL query statement below
select distinct p.email from Person p join Person a where P.email=a.email and p.id<a.id