select Customers.CustomerID 
from Customers
except
select Customers.CustomerID
from Customers, Orders
where Customers.CustomerID = Orders.CustomerID

-------------------------

select Suppliers.CompanyName 
from Suppliers, Products, Categories
where Suppliers.SupplierId = Products.SupplierID and Products.CategoryID = Categories.CategoryID
and ( CategoryName = 'Beverages' and Categories.CategoryName = 'Condiments' )

select Suppliers.CompanyName
from Suppliers, Products, Categories
where Suppliers.SupplierId = Products.SupplierID and Products.CategoryID = Categories.CategoryID
and CategoryName = 'Beverages'
intersect
select Suppliers.CompanyName
from Suppliers, Products, Categories
where Suppliers.SupplierId = Products.SupplierID and Products.CategoryID = Categories.CategoryID
and CategoryName = 'Condiments'


/* For a mass-mailing purpose, get the 
list of all names, addresses, cities and 
postal codes known to the database 
and remove duplicates from the result 
if any (these data are stored in the 
customers and employees tables). */

select Customers.CompanyName, Customers.Address, Customers.City, Customers.PostalCode
from Customers
union
select Employees.FirstName, Employees.Address, Employees.City, Employees.PostalCode
from Employees


/* For each product ordered in March 
1998, get the product id, number of 
orders for that product and the total 
quantity ordered. Give suitable 
name(s) for any unnamed displayed 
column(s). Sort by total quantity 
descendingly */

select Products.ProductID, count([Order Details].OrderID) as NumofOrders, sum([Order Details].Quantity) as TotalQuantity
from Products, [Order Details], Orders
where [Order Details].OrderID = Orders.OrderID 
and year(OrderDate) = '1998'
and month(OrderDate) = '3'
group by Products.ProductID


/* Get the supplier names (Contact 
names) and the total number of 
supplied products for each supplier, 
for only those suppliers that supplied 
more than 3 products. Give suitable 
name(s) for any unnamed displayed 
column(s). */

select Suppliers.ContactName, count(Products.ProductID) as TotalSupplied
from Suppliers, Products 
where Products.SupplierID = Suppliers.SupplierID
group by Suppliers.ContactName
having count(Products.ProductID) > 3

/* For all customers with at least 15 
orders after 1996, get the customer id, 
total number of orders, the last order 
date and the average unit price for 
products in his/her orders . Give 
suitable name(s) for any unnamed 
displayed column(s). Display the 
result starting from customers with 
the highest number of orders. */


select Customers.CustomerID, count(Orders.OrderID) as TotalOrders, avg([Order Details].UnitPrice) as avgUnitPrice
from Customers, Orders, [Order Details]
where Customers.CustomerID = Orders.CustomerID and Orders.OrderID = [Order Details].OrderID and year (Orders.OrderDate) > 1996
group by Customers.CustomerID
having count(Orders.OrderID) > 15
order by count (Orders.OrderID) desc

-- SubQuerries

/* . Display the first name, title of all employees who live in UK and have the 
same job (title) as Janet or Steven. Sort the result by the first name of the 
employees in a descending order. */

select Employees.FirstName, Employees.Title
from Employees
where Employees.Country = 'UK' and Employees.Title in ( select Employees.Title from Employees WHERE FirstName IN ('Janet', 'Steven') )


/* Get a list of orders (with order dates) that were processed by employees 
who are not sales representatives: */

select Orders.OrderID, Orders.OrderDate
from Orders
where Orders.EmployeeID not in ( select Employees.Title from Employees where Employees.Title = 'sales representatives' )



