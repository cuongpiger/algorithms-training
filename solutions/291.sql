SELECT E.name, B.bonus
FROM Employee E LEFT JOIN Bonus B ON B.empId = E.empId
WHERE COALESCE(B.bonus, 0) < 1000
