CREATE DATABASE EmployeesProjects

-- SETUP

create table Employee (
	EmpID INT NOT NULL,
	EmpFname varchar(255) NOT NULL,
	EmpLname varchar(255) NOT NULL,
	Age INT NOT NULL,
	Check ( Age >= 18 ),
	EmailID varchar(255) NOT NULL,
	PhoneNO int NOT NULL,
	Adress varchar(255) NOT NULL
)

create table projects (
	ProjectID INT NOT NULL,
	EmpID INT NOT NULL,
	ClientID INT NOT NULL,
	ProjectName varchar(255) NOT NULL,
	ProjectStartDate DATE NOT NULL
)

INSERT INTO Employee
VALUES (1,'Vardhan', 'Kumar', 22, 'vardy@abc.com', 98765, 'Delhi'),
       (2,'Himani', 'Sharma', 32, 'himani@abc.com', 99775, 'Mumbai'),
       (3,'Aayushi', 'Shreshth', 24, 'aayushi@abc.com', 99775, 'Kolkata'),
       (4,'Hemanth', 'Sharma', 25, 'hemanth@abc.com', 98765, 'Bengaluru'),
       (5,'Swatee', 'Kapoor', 26, 'swatee@abc.com', 95445, 'Hyderabad');

INSERT INTO Projects (ProjectID, EmpID, ClientID, ProjectName, ProjectStartDate)
VALUES (111, 1, 3, 'Project1', '2019-04-21'),
       (222, 2, 1, 'Project2', '2019-02-12'),
       (333, 3, 5, 'Project3', '2019-01-10'),
       (444, 3, 2, 'Project4', '2019-04-16'),
       (555, 5, 4, 'Project5', '2019-05-23'),
       (666, 9, 1, 'Project6', '2019-01-12'),
       (777, 7, 2, 'Project7', '2019-07-25'),
       (888, 8, 3, 'Project8', '2019-08-20');



alter table employee
add constraint e_pkey PRIMARY KEY (EmpID)

alter table projects
add constraint p_fkey FOREIGN KEY (EmpID) REFERENCES Employee(EmpID)

alter table projects
drop constraint p_fkey

delete from projects

delete from Employee



Select * From employee;
Select * From projects;

  -- DOING THE EXAMPLES
 
 -- EX1 
Select Employee.EmpFname as EmployeeFullName, Employee.EmpLname as EmployeeLastName, projects.ProjectID
From Employee left outer join projects
on Employee.EmpID = projects.EmpID;

 -- EX2

