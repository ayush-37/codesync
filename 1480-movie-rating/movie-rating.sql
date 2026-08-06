# Write your MySQL query statement below
(SELECT u.name AS results
FROM MovieRating mr JOIN Users u ON u.user_id = mr.user_id  GROUP BY u.user_id ORDER BY COUNT(u.user_id) DESC, u.name ASC LIMIT 1)
UNION ALL
(SELECT m.title AS results
FROM MovieRating mr JOIN Movies m ON m.movie_id = mr.movie_id WHERE YEAR(mr.created_at) = 2020 AND MONTH(mr.created_at) = 2 GROUP BY mr.movie_id ORDER BY AVG(mr.rating) DESC, m.title ASC LIMIT 1);
