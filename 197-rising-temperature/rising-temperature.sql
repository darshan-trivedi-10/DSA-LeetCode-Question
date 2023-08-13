SELECT w1.id
FROM Weather as w1
WHERE w1.temperature > (
  SELECT w2.temperature
  FROM Weather as w2
  WHERE w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
);
