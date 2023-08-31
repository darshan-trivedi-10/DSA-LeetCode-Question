# Write your MySQL query statement below

# Users (user_id, user_name) 
# Register (contest_id, user_id)
 
SELECT contest_id, round(count(contest_id)/(SELECT COUNT(user_id) FROM Users) * 100, 2) AS percentage 
FROM Register GROUP BY contest_id ORDER BY percentage DESC, contest_id ASC;