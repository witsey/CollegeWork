SELECT * FROM Student;
SELECT * FROM Department;

SELECT Student.Name, Student.Major, Department.Name as DepartmentName
FROM Student INNER JOIN  Department
ON Student.Major = Department.Deptcode;