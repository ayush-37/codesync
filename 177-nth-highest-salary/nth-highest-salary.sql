CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        SELECT salary as getNthHighestSalary FROM (
            SELECT salary, DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk FROM Employee
        ) t
        WHERE rnk = N LIMIT 1
  );
END