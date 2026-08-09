SELECT 
    t.visited_on, 
    SUM(c.amount) AS amount, 
    ROUND(SUM(c.amount) / 7, 2) AS average_amount
FROM (
    SELECT DISTINCT visited_on
    FROM Customer
    WHERE DATE_ADD(visited_on, INTERVAL -6 DAY) >= 
          (SELECT MIN(visited_on) FROM Customer)
) t
JOIN Customer c
    ON DATEDIFF(t.visited_on, c.visited_on) <= 6 
    AND c.visited_on <= t.visited_on
GROUP BY t.visited_on
ORDER BY t.visited_on;