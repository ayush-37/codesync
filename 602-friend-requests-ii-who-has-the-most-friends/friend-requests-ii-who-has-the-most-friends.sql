# Write your MySQL query statement below
SELECT temp.id, temp.num 
FROM 
    (
    SELECT t.id, COUNT(t.id) AS num 
    FROM(
        SELECT requester_id as id FROM RequestAccepted 
        UNION ALL
        SELECT accepter_id as id FROM RequestAccepted 
    ) t
    GROUP by t.id) temp
    WHERE temp.num = (
        SELECT MAX(num2)
        FROM(
            SELECT COUNT(t2.id) AS num2 
            FROM(
                SELECT requester_id as id FROM RequestAccepted 
                UNION ALL
                SELECT accepter_id as id FROM RequestAccepted
            ) t2 
            GROUP BY t2.id
        ) x
    );