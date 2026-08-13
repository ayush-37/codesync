# Write your MySQL query statement below
WITH temp AS(
    SELECT buyer_id , order_date FROM Orders WHERE YEAR(order_date) = 2019
)

SELECT u.user_id AS buyer_id, u.join_date, COUNT(t.buyer_id) AS orders_in_2019
FROM Users u
LEFT JOIN temp t ON u.user_id = t.buyer_id 
GROUP BY u.user_id;