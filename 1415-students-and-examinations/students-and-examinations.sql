# Write your MySQL query statement below
# Students(ID, NAME), Subjects(SUBJECT), Examinations (ID, SUBJECT)
# ID, NAME, SUBJECT, NUMBER OF TIMES ATTENDES THE EXAM

SELECT s.student_id, s.student_name, sub.subject_name, 

COUNT(e.subject_name) AS attended_exams

FROM Students AS s CROSS JOIN Subjects AS sub

LEFT JOIN Examinations AS e 

ON s.student_id = e.student_id AND sub.subject_name = e.subject_name

GROUP BY s.student_id, sub.subject_name

ORDER BY s.student_id, sub.subject_name;

# select s.student_id, s.student_name, sb.subject_name, 
# ifnull(count(e.subject_name),0)attended_exams 

# from students s cross join subjects sb
# left join examinations e

# on e.student_id = s.student_id and e.subject_name = sb.subject_name

# group by s.student_id, s.student_name, sb.subject_name

# order by s.student_id, sb.subject_name;"
