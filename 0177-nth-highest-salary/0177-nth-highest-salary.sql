CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT DISTINCT p.salary
      FROM Employee AS p
      WHERE (
          SELECT COUNT(DISTINCT q.salary)
          FROM Employee AS q
          WHERE q.salary > p.salary
      ) = N - 1
  );
END