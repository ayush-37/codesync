# Write your MySQL query statement below
WITH relation AS(
    SELECT t1.id, COUNT(t1.p_id) AS noOfPar, count(t2.id) AS noOfchild FROM Tree t1 
    LEFT JOIN Tree t2 ON t2.p_id IS NOT NULL AND t1.id = t2.p_id GROUP BY t1.id
) 

SELECT id , CASE
                WHEN noOfPar = 0 THEN 'Root'
                WHEN noOfchild = 0 THEN 'Leaf'
                ELSE 'Inner'
            END AS type FROM relation
