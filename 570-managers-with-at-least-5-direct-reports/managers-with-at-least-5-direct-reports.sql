SELECT name
FROM Employee
WHERE Id IN (
SELECT managerId
FROM Employee
WHERE managerId IS NOT NULL
GROUP BY managerId
HAVING COUNT(*) >= 5
);