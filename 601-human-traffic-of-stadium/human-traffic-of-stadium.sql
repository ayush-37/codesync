# Write your MySQL query statement below
WITH temp AS(
    SELECT *, id - RANK() OVER(ORDER BY visit_date) AS diff FROM Stadium WHERE people >= 100
)

SELECT id, visit_date, people FROM temp WHERE diff IN (
    SELECT diff FROM temp GROUP BY diff HAVING COUNT(diff) >= 3 
) ORDER BY visit_date