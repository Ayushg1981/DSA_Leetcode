# Write your MySQL query statement below
select w.id from weather w join weather u where DATEDIFF(w.recordDate, u.recordDate) = 1 and w.temperature>u.temperature