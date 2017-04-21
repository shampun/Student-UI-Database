DROP TRIGGER IF EXISTS `mydb`.`grades_AFTER_DELETE`;

DELIMITER $$
USE `mydb`$$
CREATE DEFINER=`root`@`localhost` TRIGGER `mydb`.`grades_AFTER_DELETE` AFTER DELETE ON `grades` FOR EACH ROW
BEGIN

	DECLARE done INT DEFAULT FALSE;
    DECLARE tot_rows integer;
    DECLARE AVGconv integer;
    DECLARE newGPA decimal;
    DECLARE GPAsubtot decimal;
	DECLARE GPAcursr cursor for 
			SELECT average
            FROM grades
            WHERE Courses_has_Students_Students_idStudents = old.Courses_has_Students_Students_idStudents;
   DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
   
   
  
 SET GPAsubtot = 0;
 
OPEN GPAcursr;

read_loop: LOOP

/*SET done = FALSE ;*/

	FETCH GPAcursr
		INTO AVGconv;
IF done THEN
LEAVE read_loop;
END IF;


IF AVGconv > 89
	THEN SET newGPA = 4;
ELSEIF AVGconv > 79
    THEN SET newGPA = 3;
ELSEIF AVGconv > 69
    THEN SET newGPA = 2;
ELSEIF AVGconv > 59
    THEN SET newGPA = 1;
ELSE  
     SET newGPA = 0;    
    END IF; 
    
    SET GPAsubtot = GPAsubtot + newGPA;
    


     END LOOP;

CLOSE GPAcursr;

SELECT COUNT(*)
	INTO tot_rows
    FROM Grades
    WHERE Courses_has_Students_Students_idStudents= old.Courses_has_Students_Students_idStudents;
		
    
    
		UPDATE students
        SET GPA = (GPAsubtot)/(tot_rows)
			WHERE idStudents= old.Courses_has_Students_Students_idStudents;  

END$$
DELIMITER ;
