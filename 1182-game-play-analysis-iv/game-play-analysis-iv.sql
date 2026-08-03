# Write your MySQL query statement below
SELECT ROUND(
    SUM(
        IF(DATEDIFF(a.event_date,b.first_log) = 1,1,0)) / COUNT(DISTINCT a.player_id),2
    ) AS fraction
FROM Activity a
JOIN (
    SELECT player_id, MIN(event_date) as first_log FROM Activity GROUP BY player_id
) b
ON a.player_id = b.player_id;

