# # Write your MySQL query statement below
SELECT a1.machine_id, round(avg(a2.timestamp - a1.timestamp), 3) as processing_time
FROM Activity AS A1 
JOIN Activity AS A2 
ON A1.machine_id = A2.machine_id AND A1.process_id = A2.process_id AND A1.activity_type = 'start' AND a2.activity_type = 'end'
GROUP BY a1.machine_id;