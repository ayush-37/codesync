# Write your MySQL query statement below
WITH temp AS(
    SELECT e.name AS Employee, e.salary AS Salary, d.id AS dId, d.name AS Department, DENSE_RANK() OVER(
        PARTITION BY  d.id ORDER BY e.salary DESC 
    ) AS rnk
    FROM Employee e
    JOIN Department d 
    ON e.departmentId = d.id
)
SELECT Department, Employee, Salary 
FROM temp 
WHERE rnk = 1;