# Write your MySQL query statement below
SELECT c.visited_on,
(
    SELECT SUM(amount) FROM customer WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
) AS amount,
ROUND((
    SELECT SUM(amount)/7 FROM customer WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
),2)AS average_amount
FROM Customer c 
WHERE visited_on IN(
    SELECT visited_on FROM Customer WHERE DATE_ADD(visited_on, INTERVAL -6 DAY) >= (SELECT MIN(visited_on) FROM Customer)
) 
GROUP BY visited_on 
ORDER BY visited_on;