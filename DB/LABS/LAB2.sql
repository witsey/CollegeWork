
-- LAB2

SELECT TOP 7 * FROM Student ORDER BY Name;
SELECT * FROM Department;
SELECT * FROM Course;
SELECT * FROM Registered;

INSERT INTO Student
VALUES (20220846, 'Ilias', 'Cairo', 18, 'IT')


SELECT * FROM Student WHERE ( Major IN ( SELECT Deptcode FROM Department WHERE (Deptcode = 'IS') ));

DELETE FROM student where Name = 'akram'

INSERT INTO Student
VALUES(20220802, 'Akram', 'Cairo', 19, 'CS');

INSERT INTO Department
VALUES('CS', 'Computer Science');

INSERT INTO department values ('IS','Information System')

update Student 
set age=age-1



-- constraints

ALTER TABLE Student
Add CONSTRAINT Pkey PRIMARY KEY (SSN);

ALTER TABLE Student
ADD CONSTRAINT Fkey FOREIGN KEY (Major) REFERENCES  Department(Deptcode);


SELECT * FROM STUDENT where MAJOR = 'CS' OR MAJOR = 'IS'