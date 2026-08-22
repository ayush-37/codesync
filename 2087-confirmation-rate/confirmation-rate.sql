# Write your MySQL query statement below
select distinct s.user_id ,round(count(case when c.action = 'confirmed' then 1 end)/count(*),2) as confirmation_rate
from Signups s left join confirmations c on s.user_id = c.user_id
group by s.user_id;