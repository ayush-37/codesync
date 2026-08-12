# Write your MySQL query statement below
WITH temp AS(
    SELECT 
        t.status,
        t.request_at,
        u1.banned AS banClient,
        u2.banned AS banDriver
    FROM Trips t
    JOIN Users u1
    ON t.client_id = u1.users_id
    JOIN Users u2
    ON t.driver_id = u2.users_id
)

SELECT request_at AS Day, 
    ROUND(
        SUM(
            IF (
                (status = 'cancelled_by_driver' 
                OR status = 'cancelled_by_client') 
                AND banClient = 'No' 
                AND banDriver = 'No',
                1, 
                0
            )
        )
        /
        SUM(
            IF (
                banClient = 'No' 
                AND banDriver = 'No', 
                1, 
                0
            )
        ),
        2
    ) AS 'Cancellation Rate' 
FROM temp 
WHERE request_at >= '2013-10-01' 
    AND request_at <= '2013-10-03'
GROUP BY request_at 
HAVING SUM(
    IF(
        banClient = 'No' AND banDriver = 'No',
        1,
        0
    )
) > 0
ORDER BY request_at