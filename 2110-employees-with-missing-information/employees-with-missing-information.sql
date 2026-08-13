# Write your MySQL query statement below
WITH total AS(
    SELECT e.employee_id,e.name,s.salary FROM Employees e LEFT JOIN Salaries s ON e.employee_id = s.employee_id
    UNION
    SELECT s.employee_id,e.name,s.salary FROM Employees e RIGHT JOIN Salaries s ON e.employee_id = s.employee_id
)

SELECT employee_id FROM total WHERE name IS NULL OR salary IS NULL ORDER BY employee_id