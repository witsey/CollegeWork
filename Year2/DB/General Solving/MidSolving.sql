-- LEC 10 EXs

 /* 1: Get the total quantity ordered for each displayed product name with units in
stock higher than 30. Restrict the result for those products having total
ordered quantity in the range between 1000 and 1500. */

select Products.ProductName, sum([Order Details].Quantity) as TotalQuantityOrdered
from [Order Details], Products
where [Order Details].ProductID = Products.ProductID and Products.UnitsInStock > 30
group by Products.ProductName
having sum([Order Details].Quantity) Between 1000 and 1500



/* 2: For each displayed country name, show how many products were supplied by
suppliers who have got a fax number. Restrict the result for those countries
having less than five supplied products. */

select Suppliers.Country, count(Products.ProductID) as ' Supplied '
from Suppliers, Products
where Suppliers.SupplierID = Products.SupplierID and Suppliers.Fax IS NOT NULL
group by Suppliers.Country
having count(Products.ProductID) < 5



/* 3: Display the first name, country, job title and birth date of all employees who
are not working as Sales Managers, were born before 1958 and are working in
the same country as the employees with first name: Mai. Sort the result by the
first name of the employees in an ascending order. */


select Employees.FirstName, Employees.Country, Employees.Title, Employees.BirthDate
from Employees
where Employees.Title != 'Sales Manager' and year(Employees.BirthDate) > 1958
and Employees.Country in  ( select Employees.Country from Employees where Employees.FirstName = 'Mai' )
order by Employees.FirstName asc


/* 4: Get the names of customers (Contact names), the order dates of their orders
in addition to the unit price of these orders. */

select Customers.ContactName, Orders.OrderDate, [Order Details].UnitPrice
from Customers, Orders, [Order Details]
where Customers.CustomerID = Orders.CustomerID and Orders.OrderID = [Order Details].OrderID

-- eazy lol


