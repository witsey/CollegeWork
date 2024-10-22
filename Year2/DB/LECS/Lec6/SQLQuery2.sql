CREATE TABLE mentors (
	id INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
	name varchar(255) NOT NULL,
	age int NOT NULL,
	student int NOT NULL,
	FOREIGN KEY(student) references students(id)
);

INSERT INTO dbo.mentors (name, age, student) values('Issa', 40, 4)
SELECT id FROM students
SELECT * FROM mentors WHERE ( student = ( SELECT id FROM students WHERE ( name = 'omar' ))  )
DELETE FROM students WHERE (id = 5)
SELECT id FROM students WHERE ( name = 'omar' )
SELECT mentors.name, mentors.age, students.name, students.GPA FROM mentors inner join students on mentors.student = students.id 
