-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `mydb` ;

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`admins`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`admins` ;

CREATE TABLE IF NOT EXISTS `mydb`.`admins` (
  `idAdmins` INT(11) NOT NULL,
  `AdmUserN` VARCHAR(45) NULL DEFAULT NULL,
  `AdmPassW` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`idAdmins`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mydb`.`instructors`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`instructors` ;

CREATE TABLE IF NOT EXISTS `mydb`.`instructors` (
  `idInstructors` INT(11) NOT NULL,
  `InstrFName` VARCHAR(45) NULL DEFAULT NULL,
  `InstrLName` VARCHAR(45) NULL DEFAULT NULL,
  `InstrUserN` VARCHAR(45) NULL DEFAULT NULL,
  `InstrPassW` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idInstructors`),
  INDEX `InstrID` (`idInstructors` ASC),
  INDEX `InstrFName` (`InstrFName` ASC),
  INDEX `InstrLName` (`InstrLName` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mydb`.`students`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`students` ;

CREATE TABLE IF NOT EXISTS `mydb`.`students` (
  `idStudents` INT(11) NOT NULL,
  `StuFName` VARCHAR(45) NULL DEFAULT NULL,
  `StuLName` VARCHAR(45) NULL DEFAULT NULL,
  `StuUserN` VARCHAR(45) NULL DEFAULT NULL,
  `StuPassW` VARCHAR(45) NULL DEFAULT NULL,
  `GPA` DECIMAL(2,1) NULL DEFAULT NULL COMMENT 'this is a derived attribute that makes a calculation based off all class averages of that student',
  PRIMARY KEY (`idStudents`),
  INDEX `StuFName` (`StuFName` ASC),
  INDEX `stulname` (`StuLName` ASC),
  INDEX `stuID` (`idStudents` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mydb`.`courses`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`courses` ;

CREATE TABLE IF NOT EXISTS `mydb`.`courses` (
  `idCourses` INT(11) NOT NULL,
  `CourseName` VARCHAR(45) NULL DEFAULT NULL,
  `StuFName` VARCHAR(45) NULL DEFAULT NULL,
  `StuLName` VARCHAR(45) NULL DEFAULT NULL,
  `idStudents` INT(11) NOT NULL,
  `InstrFName` VARCHAR(45) NULL DEFAULT NULL,
  `InstrLName` VARCHAR(45) NULL DEFAULT NULL,
  `Instructors_idInstructors` INT(11) NOT NULL,
  PRIMARY KEY (`idCourses`, `idStudents`),
  INDEX `fk_Courses_Instructors1_idx` (`Instructors_idInstructors` ASC),
  INDEX `fk_Courses_Students1_idx` (`StuFName` ASC),
  INDEX `fk_courses_stuLName_idx` (`StuLName` ASC),
  INDEX `fk_courses_stuID_idx` (`idStudents` ASC),
  INDEX `fk_courses_InstrFName_idx` (`InstrFName` ASC),
  INDEX `fk_courses_InstrLName_idx` (`InstrLName` ASC),
  CONSTRAINT `fk_Courses_Instructors1`
    FOREIGN KEY (`Instructors_idInstructors`)
    REFERENCES `mydb`.`instructors` (`idInstructors`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_InstrFName`
    FOREIGN KEY (`InstrFName`)
    REFERENCES `mydb`.`instructors` (`InstrFName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_InstrLName`
    FOREIGN KEY (`InstrLName`)
    REFERENCES `mydb`.`instructors` (`InstrLName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_stuFName`
    FOREIGN KEY (`StuFName`)
    REFERENCES `mydb`.`students` (`StuFName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_stuID`
    FOREIGN KEY (`idStudents`)
    REFERENCES `mydb`.`students` (`idStudents`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_stuLName`
    FOREIGN KEY (`StuLName`)
    REFERENCES `mydb`.`students` (`StuLName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mydb`.`courses_has_students`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`courses_has_students` ;

CREATE TABLE IF NOT EXISTS `mydb`.`courses_has_students` (
  `Courses_idCourses` INT(11) NOT NULL,
  `Students_idStudents` INT(11) NOT NULL,
  PRIMARY KEY (`Courses_idCourses`, `Students_idStudents`),
  INDEX `fk_Courses_has_Students_Students1_idx` (`Students_idStudents` ASC),
  INDEX `fk_Courses_has_Students_Courses_idx` (`Courses_idCourses` ASC),
  CONSTRAINT `fk_Courses_has_Students_Courses`
    FOREIGN KEY (`Courses_idCourses`)
    REFERENCES `mydb`.`courses` (`idCourses`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_Courses_has_Students_Students1`
    FOREIGN KEY (`Students_idStudents`)
    REFERENCES `mydb`.`students` (`idStudents`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mydb`.`grades`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`grades` ;

CREATE TABLE IF NOT EXISTS `mydb`.`grades` (
  `Test1` INT(11) NULL DEFAULT NULL,
  `Test2` INT(11) NULL DEFAULT NULL,
  `Test3` INT(11) NULL DEFAULT NULL,
  `average` INT(11) GENERATED ALWAYS AS ((((`Test1` + `Test2`) + `Test3`) / 3)) STORED,
  `Courses_has_Students_Courses_idCourses` INT(11) NOT NULL,
  `Courses_has_Students_Students_idStudents` INT(11) NOT NULL,
  PRIMARY KEY (`Courses_has_Students_Courses_idCourses`, `Courses_has_Students_Students_idStudents`),
  INDEX `fk_Grades_Courses_has_Students1_idx` (`Courses_has_Students_Courses_idCourses` ASC, `Courses_has_Students_Students_idStudents` ASC),
  CONSTRAINT `fk_Grades_Courses_has_Students1`
    FOREIGN KEY (`Courses_has_Students_Courses_idCourses` , `Courses_has_Students_Students_idStudents`)
    REFERENCES `mydb`.`courses_has_students` (`Courses_idCourses` , `Students_idStudents`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

USE `mydb`;

DELIMITER $$

USE `mydb`$$
DROP TRIGGER IF EXISTS `mydb`.`grades_AFTER_DELETE` $$
USE `mydb`$$
CREATE
DEFINER=`root`@`localhost`
TRIGGER `mydb`.`grades_AFTER_DELETE`
AFTER DELETE ON `mydb`.`grades`
FOR EACH ROW
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


USE `mydb`$$
DROP TRIGGER IF EXISTS `mydb`.`grades_AFTER_INSERT` $$
USE `mydb`$$
CREATE
DEFINER=`root`@`localhost`
TRIGGER `mydb`.`grades_AFTER_INSERT`
AFTER INSERT ON `mydb`.`grades`
FOR EACH ROW
BEGIN

	DECLARE done INT DEFAULT FALSE;
    DECLARE tot_rows integer;
    DECLARE AVGconv integer;
    DECLARE newGPA decimal;
    DECLARE GPAsubtot decimal;
	DECLARE GPAcursr cursor for 
			SELECT average
            FROM grades
            WHERE Courses_has_Students_Students_idStudents = NEW.Courses_has_Students_Students_idStudents;
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
    WHERE Courses_has_Students_Students_idStudents=NEW.Courses_has_Students_Students_idStudents;
		
    
    
		UPDATE students
        SET GPA = (GPAsubtot)/(tot_rows)
			WHERE idStudents=NEW.Courses_has_Students_Students_idStudents;  
END$$


USE `mydb`$$
DROP TRIGGER IF EXISTS `mydb`.`grades_AFTER_UPDATE` $$
USE `mydb`$$
CREATE
DEFINER=`root`@`localhost`
TRIGGER `mydb`.`grades_AFTER_UPDATE`
AFTER UPDATE ON `mydb`.`grades`
FOR EACH ROW
BEGIN

	DECLARE done INT DEFAULT FALSE;
    DECLARE tot_rows integer;
    DECLARE AVGconv integer;
    DECLARE newGPA decimal;
    DECLARE GPAsubtot decimal;
	DECLARE GPAcursr cursor for 
			SELECT average
            FROM grades
            WHERE Courses_has_Students_Students_idStudents = NEW.Courses_has_Students_Students_idStudents;
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
    WHERE Courses_has_Students_Students_idStudents=NEW.Courses_has_Students_Students_idStudents;
		
    
    
		UPDATE students
        SET GPA = (GPAsubtot)/(tot_rows)
			WHERE idStudents=NEW.Courses_has_Students_Students_idStudents;   
 
END$$


DELIMITER ;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
