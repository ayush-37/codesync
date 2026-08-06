# Write your MySQL query statement below
SELECT CASE
            WHEN MOD(id,2) = 0 THEN id-1
            WHEN id = (SELECT MAX(id) FROM SEAT) THEN id
            WHEN MOD(id,2) = 1 THEN id+1
        END AS id, student 
    FROM Seat ORDER BY id;