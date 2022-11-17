-- Link: https://leetcode.com/problems/combine-two-tables/?envType=study-plan&id=sql-i

SELECT FirstName, LastName, City, State FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId