# Student-UI-Database
            query.exec("UPDATE `mydb`.`grades` SET `Test2`='0' WHERE `Courses_has_Students_Courses_idCourses`='"+CourseID+"' and`Courses_has_Students_Students_idStudents`='"+StudentID+"'");

The goal of this project is to create a program that acts with three users: Admin, Teacher, and student.

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
