# Cinema (id, movie, description, rating)
SELECT * FROM Cinema 
WHERE mod(id, 2) = 1 AND description != 'boring' ORDER BY rating DESC;