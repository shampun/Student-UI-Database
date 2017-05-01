-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: localhost    Database: mydb
-- ------------------------------------------------------
-- Server version	5.7.17-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `admins`
--

DROP TABLE IF EXISTS `admins`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `admins` (
  `idAdmins` int(11) NOT NULL,
  `AdmUserN` varchar(45) DEFAULT NULL,
  `AdmPassW` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idAdmins`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admins`
--

LOCK TABLES `admins` WRITE;
/*!40000 ALTER TABLE `admins` DISABLE KEYS */;
INSERT INTO `admins` VALUES (1,'dellis0','LmHPuH'),(2,'sharper1','Mjg6xvdhxK5Q'),(3,'ahall2','v8ODBwxHWU'),(4,'bhawkins3','HeHxXLkr'),(5,'vnelson4','nl9LacZb'),(6,'buthead','fart444');
/*!40000 ALTER TABLE `admins` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `courses`
--

DROP TABLE IF EXISTS `courses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `courses` (
  `idCourses` int(11) NOT NULL,
  `CourseName` varchar(45) DEFAULT NULL,
  `StuFName` varchar(45) DEFAULT NULL,
  `StuLName` varchar(45) DEFAULT NULL,
  `idStudents` int(11) NOT NULL,
  `InstrFName` varchar(45) DEFAULT NULL,
  `InstrLName` varchar(45) DEFAULT NULL,
  `Instructors_idInstructors` int(11) NOT NULL,
  PRIMARY KEY (`idCourses`,`idStudents`),
  KEY `fk_Courses_Instructors1_idx` (`Instructors_idInstructors`),
  KEY `fk_Courses_Students1_idx` (`StuFName`),
  KEY `fk_courses_stuLName_idx` (`StuLName`),
  KEY `fk_courses_stuID_idx` (`idStudents`),
  KEY `fk_courses_InstrFName_idx` (`InstrFName`),
  KEY `fk_courses_InstrLName_idx` (`InstrLName`),
  CONSTRAINT `fk_Courses_Instructors1` FOREIGN KEY (`Instructors_idInstructors`) REFERENCES `instructors` (`idInstructors`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_InstrFName` FOREIGN KEY (`InstrFName`) REFERENCES `instructors` (`InstrFName`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_InstrLName` FOREIGN KEY (`InstrLName`) REFERENCES `instructors` (`InstrLName`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_stuFName` FOREIGN KEY (`StuFName`) REFERENCES `students` (`StuFName`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_stuID` FOREIGN KEY (`idStudents`) REFERENCES `students` (`idStudents`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_courses_stuLName` FOREIGN KEY (`StuLName`) REFERENCES `students` (`StuLName`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `courses`
--

LOCK TABLES `courses` WRITE;
/*!40000 ALTER TABLE `courses` DISABLE KEYS */;
INSERT INTO `courses` VALUES (1,'MATH 3324','Shawn','Gonzalez',3,'Christine','Martinez',1),(1,'MATH 3324','Christine','Alexander',5,'Christine','Martinez',1),(1,'MATH 3324','Norma','Henry',6,'Christine','Martinez',1),(1,'MATH 3324','Ralph','Hayes',9,'Christine','Martinez',1),(1,'MATH 3324','Phillip','Larson',10,'Christine','Martinez',1),(1,'MATH 3324','Daniel','Cooper',13,'Christine','Martinez',1),(2,'ENG 2406','Nancy','Jenkins',1,'Theresa','Burns',2),(2,'ENG 2406','Betty','Harvey',4,'Theresa','Burns',2),(2,'ENG 2406','Pamela','Reyes',7,'Theresa','Burns',2),(2,'ENG 2406','Phillip','Larson',10,'Theresa','Burns',2),(3,'HIST 2133','Shawn','Gonzalez',3,'Kathleen','Rogers',4),(3,'HIST 2133','Norma','Henry',6,'Kathleen','Rogers',4),(3,'HIST 2133','Ralph','Hayes',9,'Kathleen','Rogers',4),(3,'HIST 2133','Billy','Wallace',12,'Kathleen','Rogers',4),(3,'HIST 2133','Debra','Campbell',15,'Kathleen','Rogers',4),(4,'BIOL 3265','Christine','Alexander',5,'Harry','Arnold',3),(4,'BIOL 3265','Ralph','Hayes',9,'Harry','Arnold',3),(4,'BIOL 3265','Debra','Campbell',15,'Harry','Arnold',3);
/*!40000 ALTER TABLE `courses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `courses_has_students`
--

DROP TABLE IF EXISTS `courses_has_students`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `courses_has_students` (
  `Courses_idCourses` int(11) NOT NULL,
  `Students_idStudents` int(11) NOT NULL,
  PRIMARY KEY (`Courses_idCourses`,`Students_idStudents`),
  KEY `fk_Courses_has_Students_Students1_idx` (`Students_idStudents`),
  KEY `fk_Courses_has_Students_Courses_idx` (`Courses_idCourses`),
  CONSTRAINT `fk_Courses_has_Students_Courses` FOREIGN KEY (`Courses_idCourses`) REFERENCES `courses` (`idCourses`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_Courses_has_Students_Students1` FOREIGN KEY (`Students_idStudents`) REFERENCES `students` (`idStudents`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `courses_has_students`
--

LOCK TABLES `courses_has_students` WRITE;
/*!40000 ALTER TABLE `courses_has_students` DISABLE KEYS */;
INSERT INTO `courses_has_students` VALUES (3,3),(1,6),(3,6),(1,9),(3,9),(1,10),(3,12),(1,13);
/*!40000 ALTER TABLE `courses_has_students` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `grades`
--

DROP TABLE IF EXISTS `grades`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `grades` (
  `Test1` int(11) DEFAULT NULL,
  `Test2` int(11) DEFAULT NULL,
  `Test3` int(11) DEFAULT NULL,
  `average` int(11) GENERATED ALWAYS AS ((((`Test1` + `Test2`) + `Test3`) / 3)) STORED,
  `Courses_has_Students_Courses_idCourses` int(11) NOT NULL,
  `Courses_has_Students_Students_idStudents` int(11) NOT NULL,
  PRIMARY KEY (`Courses_has_Students_Courses_idCourses`,`Courses_has_Students_Students_idStudents`),
  KEY `fk_Grades_Courses_has_Students1_idx` (`Courses_has_Students_Courses_idCourses`,`Courses_has_Students_Students_idStudents`),
  CONSTRAINT `fk_Grades_Courses_has_Students1` FOREIGN KEY (`Courses_has_Students_Courses_idCourses`, `Courses_has_Students_Students_idStudents`) REFERENCES `courses_has_students` (`Courses_idCourses`, `Students_idStudents`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `grades`
--

LOCK TABLES `grades` WRITE;
/*!40000 ALTER TABLE `grades` DISABLE KEYS */;
INSERT INTO `grades` (`Test1`, `Test2`, `Test3`, `Courses_has_Students_Courses_idCourses`, `Courses_has_Students_Students_idStudents`) VALUES (88,90,87,1,6),(90,86,90,1,10),(89,41,100,1,13),(85,15,88,3,3),(83,75,94,3,6),(84,81,21,3,9),(88,14,55,3,12);
/*!40000 ALTER TABLE `grades` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `instructors`
--

DROP TABLE IF EXISTS `instructors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `instructors` (
  `idInstructors` int(11) NOT NULL,
  `InstrFName` varchar(45) DEFAULT NULL,
  `InstrLName` varchar(45) DEFAULT NULL,
  `InstrUserN` varchar(45) DEFAULT NULL,
  `InstrPassW` varchar(45) NOT NULL,
  PRIMARY KEY (`idInstructors`),
  KEY `InstrID` (`idInstructors`),
  KEY `InstrFName` (`InstrFName`),
  KEY `InstrLName` (`InstrLName`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `instructors`
--

LOCK TABLES `instructors` WRITE;
/*!40000 ALTER TABLE `instructors` DISABLE KEYS */;
INSERT INTO `instructors` VALUES (1,'Christine','Martinez','lame','city'),(2,'Theresa','Burns','tburns1','5a98d2Q3vpl'),(3,'Harry','Arnold','harnold2','ZLPKEZM3'),(4,'Kathleen','Rogers','krogers3','G6euwiD');
/*!40000 ALTER TABLE `instructors` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `students`
--

DROP TABLE IF EXISTS `students`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `students` (
  `idStudents` int(11) NOT NULL,
  `StuFName` varchar(45) DEFAULT NULL,
  `StuLName` varchar(45) DEFAULT NULL,
  `StuUserN` varchar(45) DEFAULT NULL,
  `StuPassW` varchar(45) DEFAULT NULL,
  `GPA` decimal(2,1) DEFAULT NULL COMMENT 'this is a derived attribute that makes a calculation based off all class averages of that student',
  PRIMARY KEY (`idStudents`),
  KEY `StuFName` (`StuFName`),
  KEY `stulname` (`StuLName`),
  KEY `stuID` (`idStudents`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `students`
--

LOCK TABLES `students` WRITE;
/*!40000 ALTER TABLE `students` DISABLE KEYS */;
INSERT INTO `students` VALUES (1,'Nancy','Jenkins','studnet','sand',NULL),(2,'Daniel','Cooper','dcooper1','EqFKQ6J2e',NULL),(3,'Shawn','Gonzalez','aj','sand',0.5),(4,'Betty','Harvey','bharvey3','2Bron8a4l',3.0),(5,'Christine','Alexander','calexander4','ytpPxlwWET2G',1.0),(6,'Norma','Henry','nhenry5','eRc5z3mLau',3.0),(7,'Pamela','Reyes','preyes6','t8QuGyy0FV0',0.0),(8,'Russell','Morris','rmorris7','6tuTgWprbzj',NULL),(9,'Ralph','Hayes','rhayes8','AoQHMf',1.0),(10,'Phillip','Larson','plarson9','DTn6OKP5',3.0),(11,'Chris','Reynolds','creynoldsa','Uz6uf7D',0.0),(12,'Billy','Wallace','bwallaceb','DqW99CsrYmw',1.5),(13,'Daniel','Perkins','dperkinsc','I0D2OF',2.0),(14,'James','Boyd','jboydd','dOdyWVNtqU',NULL),(15,'Debra','Campbell','dcampbelle','nXFWrVIjd',NULL),(16,'Alex','Beaty','abeaty28','Lkdkei&98',NULL),(17,'Bart','Simpson',NULL,NULL,0.0);
/*!40000 ALTER TABLE `students` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-04-30 22:43:20
