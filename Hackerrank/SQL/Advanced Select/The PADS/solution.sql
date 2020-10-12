SELECT CONCAT(Name, '(', LEFT(Occupation, 1), ')') AS 'Name(Profession)'
  FROM OCCUPATIONS
 ORDER BY Name;

SELECT CONCAT('There are a total of ', COUNT(*), ' ', LOWER(Occupation), 's.')
  FROM OCCUPATIONS
 GROUP BY Occupation
 ORDER BY COUNT(*),
          Occupation;
