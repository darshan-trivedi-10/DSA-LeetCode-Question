# # Write your MySQL query statement below
# # Queries (query_name, result, position, rating)
# SELECT 
# query_name, 
# ROUND(AVG(rating/position),2) AS quality,
# (SUM(CASE WHEN rating < 3 then 1 else 0 END))/COUNT(query_name)) AS poor_query_percentage
# FROM Queries 
# GROUP BY query_name;

select
query_name,
round(avg(cast(rating as decimal) / position), 2) as quality,
round(sum(case when rating < 3 then 1 else 0 end) * 100 / count(*), 2) as poor_query_percentage
from
queries
group by
query_name;