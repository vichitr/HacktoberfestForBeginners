SELECT Name
  FROM Students s
       INNER JOIN Friends f
       ON s.ID = f.ID

       INNER JOIN Packages sp
       ON s.ID = sp.ID

       INNER JOIN Packages fp
       ON f.Friend_ID = fp.ID
 WHERE fp.Salary > sp.Salary
 ORDER BY fp.Salary;
