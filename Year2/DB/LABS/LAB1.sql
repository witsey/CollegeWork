
-- LAB1

-- (creating the database) CREATE DATABASE University;


CREATE TABLE Student
(
	SSN INT NOT NULL,
	Name varchar(255) NOT NULL,
	City varchar(255) DEFAULT 'Cairo',
	Age INT NOT NULL,
	CHECK (Age>=18),
	Major varchar(5) NOT NULL 
);

-- ALTERING THE TABLE TO MAKE THE SSN COLUMN PRIMARY
ALTER TABLE Student
Add CONSTRAINT Pkey PRIMARY KEY (SSN);

ALTER TABLE Student
ADD CONSTRAINT Fkey FOREIGN KEY (Major) REFERENCES  Department(Deptcode);



CREATE TABLE Course 
(
	CrsCode SMALLINT NOT NULL,
	Name varchar(45) UNIQUE,
	PRIMARY KEY (CrsCode)
);

CREATE TABLE Registered
(
	SSN INT NOT NULL,
	CrsCode SMALLINT NOT NULL,
	Semester varchar(50) NOT NULL,
	[Year] varchar(45)
);

ALTER TABLE Registered
ADD PRIMARY KEY (SSN, CrsCode);

ALTER TABLE Registered
ADD FOREIGN KEY (SSN) REFERENCES Students(SSN);

ALTER TABLE Registered
ADD FOREIGN KEY (Crscode) REFERENCES Course(CrsCode)

 

CREATE TABLE Department 
(
	Deptcode VARCHAR(10) NOT NULL,
	Name varchar(50) NOT NULL
);

DROP TABLE Department;




SELECT * FROM Student;
SELECT * FROM Course;
SELECT * FROM Registered;
SELECT * FROM Department;

-- SOLVING LAB1 EXs

ALTER TABLE Department
ADD StudentsNumber INT DEFAULT 0;

ALTER TABLE Students
DROP COLUMN Major;

ALTER TABLE Students
ALTER COLUMN Name VARCHAR(155);

ALTER TABLE Department
ADD CONSTRAINT checker CHECK (Deptcode IN ('IS','CS','IT','DS'));

ALTER TABLE Department
DROP CONSTRAINT checker;

ALTER TABLE DEPARTMENT
ALTER COLUMN Deptcode Varchar(5) NOT NULL;

ALTER TABLE DEPARTMENT
DROP CONSTRAINT PK__Departme__AC900527C9C6AC07;

ALTER TABLE DEPARTMENT
ADD CONSTRAINT Pkey_Dept PRIMARY KEY (Deptcode);