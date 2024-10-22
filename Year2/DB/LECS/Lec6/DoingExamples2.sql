CREATE TABLE employees (
  employeeNumber INT PRIMARY KEY,
  lastName VARCHAR(255) NOT NULL,
  firstName VARCHAR(255) NOT NULL,
  extension VARCHAR(255),
  email VARCHAR(255),
  officeCode VARCHAR(255),
  reportsTo INT,
  jobTitle VARCHAR(255)
);

CREATE TABLE offices (
  officeCode VARCHAR(255) PRIMARY KEY,
  city VARCHAR(255) NOT NULL,
  phone VARCHAR(255) NOT NULL,
  addressLine1 VARCHAR(255),
  addressLine2 VARCHAR(255),
  state VARCHAR(255),
  country VARCHAR(255) NOT NULL,
  postalCode VARCHAR(255),
  territory VARCHAR(255)
);

CREATE TABLE customers (
  customerNumber INT PRIMARY KEY,
  customerName VARCHAR(255) NOT NULL,
  contactLastName VARCHAR(255) NOT NULL,
  contactFirstName VARCHAR(255) NOT NULL,
  phone VARCHAR(255),
  addressLine1 VARCHAR(255),
  addressLine2 VARCHAR(255),
  city VARCHAR(255) NOT NULL,
  state VARCHAR(255),
  postalCode VARCHAR(255),
  country VARCHAR(255) NOT NULL
);

CREATE TABLE orders (
  orderNumber INT PRIMARY KEY,
  customerNumber INT NOT NULL,
  orderDate DATE,
  requiredDate DATE,
  shippedDate DATE,
  status VARCHAR(255),
  comments TEXT,
  FOREIGN KEY (customerNumber) REFERENCES customers(customerNumber)
);

CREATE TABLE payments (
  customerNumber INT NOT NULL,
  checkNumber VARCHAR(255) PRIMARY KEY,
  paymentDate DATE,
  amount DECIMAL(10,2) NOT NULL,
  FOREIGN KEY (customerNumber) REFERENCES customers(customerNumber)
);



INSERT INTO employees (employeeNumber, lastName, firstName, extension, email, officeCode, reportsTo, jobTitle)
VALUES (10001, 'King', 'Steven', '1234', 'steven.king@sakila.com', '1', NULL, 'President'),
       (10002, 'Hutchinson', 'William', '5555', 'william.hutchinson@sakila.com', '2', 10001, 'VP Sales'),
       (10003, 'Norris', 'Susan', '4444', 'susan.norris@sakila.com', '3', 10001, 'VP Marketing'),
       (10004, 'Adams', 'Karen', '3333', 'karen.adams@sakila.com', '4', 10002, 'Sales Manager');


INSERT INTO offices (officeCode, city, phone, addressLine1, addressLine2, state, country, postalCode, territory)
VALUES ('1', 'San Francisco', '(415) 555-0999', '909 Main St', '', 'CA', 'US', '94105', 'NA'),
       ('2', 'Los Angeles', '(213) 555-0999', '1600 Wilshire Blvd', 'Suite 100', 'CA', 'US', '90010', 'NA'),
       ('3', 'Chicago', '(312) 555-0999', '333 Wacker Dr', '', 'IL', 'US', '60601', 'NA'),
       ('4', 'New York', '(212) 555-0999', '123 Wall St', '', 'NY', 'US', '10005', 'NA');

UPDATE customers
SET salesRepEmployeeNumber = 10002
WHERE customerNumber = 1002;



select employees.firstName
from employees, offices
where employees.officeCode = offices.officeCode and offices.city = 'San Francisco'

ALTER TABLE customers
ADD salesRepEmployeeNumber INT;

select employees.firstName
from employees, customers, payments
where employees.employeeNumber = customers.salesRepEmployeeNumber and customers.customerNumber = payments.customerNumber and amount > 550

select * from payments

select firstName from employees where employees.employeeNumber in (select salesRepEmployeeNumber from customers where customerNumber in (select customerNumber from payments where amount > 550 ))

select salesRepEmployeeNumber from customers where customerNumber in (select customerNumber from payments where amount > 550 )

select 






