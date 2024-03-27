
-- EXAMPLE 1

SELECT Products.ProductName, Products.UnitPrice, Suppliers.CompanyName
FROM Products inner join Suppliers
On Products.SupplierID = Suppliers.SupplierID

 -- EXAMPLE 2

select Categories.CategoryName, Suppliers.CompanyName
From Categories, Products, Suppliers
where Categories.CategoryID = Products.CategoryID and Products.SupplierID = Suppliers.SupplierID

 -- EXAMPLE 3
select Customers.CompanyName, orders.OrderDate
from Customers left join Orders
on Customers.CustomerID = Orders.CustomerID

 -- EXAMPLE 4

select Products.ProductName, Categories.CategoryName
from Products full outer join Categories
on Categories.CategoryID = Products.ProductID

 -- EXAMPLE 5
select Products.ProductName, Suppliers.CompanyName
from Products cross join Suppliers