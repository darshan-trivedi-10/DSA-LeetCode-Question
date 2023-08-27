# Signups (user_id, time_stamp)
# Confirmations(user_id, time_stamp, action)
SELECT s.user_id, round(avg(if(c.action='confirmed',1, 0)), 2) as confirmation_rate FROM Signups as s
LEFT JOIN Confirmations as c ON s.user_id = c.user_id GROUP BY s.user_id;