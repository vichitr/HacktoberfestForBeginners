SELECT salary * months AS total_earnings,
       COUNT(*)
  FROM Employee
 GROUP BY total_earnings
 ORDER BY total_earnings DESC
 LIMIT 1;
