# Student-UI-Database
            query.exec("UPDATE `mydb`.`grades` SET `Test2`='0' WHERE `Courses_has_Students_Courses_idCourses`='"+CourseID+"' and`Courses_has_Students_Students_idStudents`='"+StudentID+"'");

The goal of this project is to create a program that acts with three users: Admin, Teacher, and student.
To configure ODBC, go to the main.cpp, line 21, and use the MySQL ODBC 5.3 Unicode Driver, 
be sure to set the SERVER to 'your server name', Uid should be set to 'your user id' for your local mysql server, 
and Password= 'your password'.
ADMIN ACTIONS
------------------------------------------------------------------------------------------------------------------------------------------
+ADDGrade(int)
-
+AddStudents(String)
-
+AddTeacher(String)
-
+DelStudent(String)
-
+DelTeacher(String)
-

TEACHER ACTIONS
------------------------------------------------------------------------------------------------------------------------------------------
+AddGrade
-
+AddStudents
-
+AddTest
-
+ClassAvg
-
+DelStudent
-

STUDENT ACTIONS
------------------------------------------------------------------------------------------------------------------------------------------
+ViewClasses
-
+ViewGPA
-
+ViewGrades
-
