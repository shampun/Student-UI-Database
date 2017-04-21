-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`admins`
-- -----------------------------------------------------
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
CREATE TABLE IF NOT EXISTS `mydb`.`students` (
  `idStudents` INT(11) NOT NULL,
  `StuFName` VARCHAR(45) NULL DEFAULT NULL,
  `StuLName` VARCHAR(45) NULL DEFAULT NULL,
  `StuUserN` VARCHAR(45) NULL DEFAULT NULL,
  `StuPassW` VARCHAR(45) NULL DEFAULT NULL,
  `GPA` INT(11) NULL DEFAULT NULL COMMENT 'this is a derived attribute that makes a calculation based off all class averages of that student',
  PRIMARY KEY (`idStudents`),
  INDEX `StuFName` (`StuFName` ASC),
  INDEX `stulname` (`StuLName` ASC),
  INDEX `stuID` (`idStudents` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mydb`.`courses`
-- -----------------------------------------------------
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
CREATE TABLE IF NOT EXISTS `mydb`.`courses_has_students` (
  `Courses_idCourses` INT(11) NOT NULL,
  `Students_idStudents` INT(11) NOT NULL,
  PRIMARY KEY (`Courses_idCourses`, `Students_idStudents`),
  INDEX `fk_Courses_has_Students_Students1_idx` (`Students_idStudents` ASC),
  INDEX `fk_Courses_has_Students_Courses_idx` (`Courses_idCourses` ASC),
  CONSTRAINT `fk_Courses_has_Students_Courses`
    FOREIGN KEY (`Courses_idCourses`)
    REFERENCES `mydb`.`courses` (`idCourses`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Courses_has_Students_Students1`
    FOREIGN KEY (`Students_idStudents`)
    REFERENCES `mydb`.`students` (`idStudents`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mydb`.`averages`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`averages` (
  `Courses_has_Students_Students_idStudents` INT(11) NOT NULL,
  `Courses_has_Students_Courses_idCourses` INT(11) NOT NULL,
  `totalScore` INT(11) NULL DEFAULT NULL,
  `courseAVG` INT(11) NULL DEFAULT NULL,
  PRIMARY KEY (`Courses_has_Students_Students_idStudents`),
  INDEX `fk_averages_Courses_has_Students1_idx` (`Courses_has_Students_Courses_idCourses` ASC, `Courses_has_Students_Students_idStudents` ASC),
  CONSTRAINT `fk_averages_Courses_has_Students1`
    FOREIGN KEY (`Courses_has_Students_Courses_idCourses` , `Courses_has_Students_Students_idStudents`)
    REFERENCES `mydb`.`courses_has_students` (`Courses_idCourses` , `Students_idStudents`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `mydb`.`grades`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`grades` (
  `TestNum` INT(11) NOT NULL,
  `Score` INT(11) NULL DEFAULT NULL,
  `Courses_has_Students_Courses_idCourses` INT(11) NOT NULL,
  `Courses_has_Students_Students_idStudents` INT(11) NOT NULL,
  PRIMARY KEY (`Courses_has_Students_Students_idStudents`, `Courses_has_Students_Courses_idCourses`, `TestNum`),
  INDEX `fk_Grades_Courses_has_Students1_idx` (`Courses_has_Students_Courses_idCourses` ASC, `Courses_has_Students_Students_idStudents` ASC),
  CONSTRAINT `fk_Grades_Courses_has_Students1`
    FOREIGN KEY (`Courses_has_Students_Courses_idCourses` , `Courses_has_Students_Students_idStudents`)
    REFERENCES `mydb`.`courses_has_students` (`Courses_idCourses` , `Students_idStudents`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

USE `mydb`;

DELIMITER $$
USE `mydb`$$
CREATE
DEFINER=`root`@`localhost`
TRIGGER `mydb`.`Grades_BEFORE_INSERT`
BEFORE INSERT ON `mydb`.`grades`
FOR EACH ROW
BEGIN
	DECLARE num_row integer;
    DECLARE tot_rows integer;
    
SELECT COUNT(*)
	INTO tot_rows
    FROM Grades
    WHERE Courses_has_Students_Courses_idCourses=NEW.Courses_has_Students_Courses_idCourses AND
		Courses_has_Students_Students_idStudents=NEW.Courses_has_Students_Students_idStudents;
		
    SELECT COUNT(*)
	INTO num_row
    FROM averages
    WHERE Courses_has_Students_Courses_idCourses=NEW.Courses_has_Students_Courses_idCourses AND
		Courses_has_Students_Students_idStudents=NEW.Courses_has_Students_Students_idStudents;   
    
    IF num_row > 0 THEN
		UPDATE averages
        SET totalScore = New.Score + totalScore,
			courseAVG = totalScore/(tot_rows+1)
			WHERE Courses_has_Students_Courses_idCourses=NEW.Courses_has_Students_Courses_idCourses AND
				Courses_has_Students_Students_idStudents=NEW.Courses_has_Students_Students_idStudents;   

	ELSE
    INSERT INTO averages
		(Courses_has_Students_Students_idStudents, Courses_has_Students_Courses_idCourses, totalScore, courseAVG)
        VALUES 	(NEW.Courses_has_Students_Students_idStudents, NEW.Courses_has_Students_Courses_idCourses, new.Score, new.Score);
	
    END IF;

		
END$$


DELIMITER ;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
