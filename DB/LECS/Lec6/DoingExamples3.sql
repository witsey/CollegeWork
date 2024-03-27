CREATE TABLE products (
  productCode VARCHAR(255) PRIMARY KEY,
  productName VARCHAR(255) NOT NULL,
  productLine VARCHAR(255),
  productScale VARCHAR(255),
  productVendor VARCHAR(255),
  productDescription TEXT,
  quantityInStock INT,
  buyPrice DECIMAL(10,2),
  MSRP DECIMAL(10,2)
);

CREATE TABLE orderdetails (
  orderNumber INT,
  productCode VARCHAR(255),
  quantityOrdered INT,
  priceEach DECIMAL(10,2),
  orderLineNumber INT,
  FOREIGN KEY (productCode) REFERENCES products(productCode)
);

/* Insert sample data into products table */
INSERT INTO products (productCode, productName, productLine, productScale, productVendor, productDescription, quantityInStock, buyPrice, MSRP)
VALUES ('A101', 'Tablet', 'Electronics', 'High', 'Vendor A', 'A sleek and powerful tablet computer.', 100, 299.99, 399.99),
       ('B202', 'Laptop', 'Electronics', 'High', 'Vendor B', 'A high-performance laptop for business and gaming.', 50, 899.99, 1299.99),
       ('C303', 'Smartphone', 'Electronics', 'Low', 'Vendor C', 'A basic smartphone for everyday use.', 200, 99.99, 149.99),
       ('D404', 'Smartwatch', 'Electronics', 'Low', 'Vendor D', 'A stylish smartwatch with fitness tracking features.', 150, 129.99, 199.99);

/* Insert sample data into orderdetails table */
INSERT INTO orderdetails (orderNumber, productCode, quantityOrdered, priceEach, orderLineNumber)
VALUES (1000, 'A101', 2, 299.99, 1),
       (1000, 'C303', 1, 99.99, 2),
       (1001, 'B202', 1, 899.99, 1),
       (1002, 'D404', 3, 129.99, 1);

Select orderdetails.orderNumber, products.productName, orderdetails.quantityOrdered
From products inner join orderdetails
on orderdetails.productCode = products.productCode

