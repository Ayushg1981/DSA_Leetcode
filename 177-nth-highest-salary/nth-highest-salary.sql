CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
        select IFNULL((select distinct salary from Employee order by salary desc limit 1 offset n),NULL) as SecondHighestSalary
  );
END