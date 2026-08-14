# Write your MySQL query statement below
WITH temp AS(
    SELECT product_id, MAX(change_date) AS Last FROM Products WHERE change_date <= '2019-08-16' GROUP BY product_id
),
newTemp AS(
    SELECT p.product_id, p.new_price FROM Products p JOIN temp ON p.product_id = temp.product_id AND p.change_date = temp.last 
)

SELECT t.product_id, COALESCE(newTemp.new_price,10) AS price FROM (SELECT DISTINCT product_id FROM Products)t LEFT JOIN newTemp ON newTemp.product_id = t.product_id 