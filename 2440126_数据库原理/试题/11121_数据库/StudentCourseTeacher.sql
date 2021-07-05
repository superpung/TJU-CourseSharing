-- =============================================
-- 创建数据库
-- =============================================
USE master

IF EXISTS (SELECT * 
	   FROM   master..sysdatabases 
	   WHERE  name = N'StudentCourseTeacher')
	DROP DATABASE StudentCourseTeacher
GO

CREATE DATABASE StudentCourseTeacher
GO

-- =============================================
-- 转到新建数据库
-- =============================================
USE StudentCourseTeacher
GO

-- =============================================
-- 创建数据表
-- =============================================

-- ----------------------------------------
-- 学生
-- ----------------------------------------
CREATE TABLE Student
(
	sno			CHAR(5),
	sname		VARCHAR(10)	NOT NULL,
	ssex		CHAR(2)		NOT NULL,
	sbirth		DATETIME	NOT NULL,
	sdept		CHAR(2)		NOT NULL,
	CONSTRAINT Student_PK PRIMARY KEY(sno)
)
GO

-- ----------------------------------------
-- 教师
-- ----------------------------------------
CREATE TABLE Teacher
(
	tno			CHAR(5),
	tname		VARCHAR(10)	NOT NULL,
	tdept		CHAR(2)		NOT NULL,
	CONSTRAINT Teacher_PK PRIMARY KEY(tno)
)
GO

-- ----------------------------------------
-- 课程
-- ----------------------------------------
CREATE TABLE Course
(
	cno		SMALLINT,
	cname		VARCHAR(20)	NOT NULL,
	ccredit		SMALLINT	NOT NULL,
	tno		CHAR(5),
	CONSTRAINT Course_PK PRIMARY KEY(cno),
	CONSTRAINT Course_Teacher_FK FOREIGN KEY(tno) REFERENCES Teacher(tno)
)
GO

-- ----------------------------------------
-- 学生选课 关系
-- ----------------------------------------
CREATE TABLE SC
(
	sno		CHAR(5),
	cno		SMALLINT,
	score		CHAR(5),
	
	CONSTRAINT SC_PK PRIMARY KEY(sno, cno),
	CONSTRAINT SC_Student_FK FOREIGN KEY(sno) REFERENCES Student(sno),
	CONSTRAINT SC_Course_FK FOREIGN KEY(cno) REFERENCES Course(cno)
)
GO


-- =============================================
-- 插入样本数据
-- =============================================

INSERT INTO Student VALUES ('08001', '张三', '男', '1988-02-19', 'CS')
INSERT INTO Student VALUES ('08002', '李四', '女', '1989-01-09', 'CS')
INSERT INTO Student VALUES ('08003', '王五', '女', '1990-12-08', 'CE')
INSERT INTO Student VALUES ('08004', '赵六', '男', '1989-08-30', 'IS')
GO

INSERT INTO Teacher VALUES ('05001', '张小明', 'CS')
INSERT INTO Teacher VALUES ('05002', '王小华', 'IS')
INSERT INTO Teacher VALUES ('05003', '李小强', 'CS')
INSERT INTO Teacher VALUES ('05004', '赵小兰', 'CE')
GO

INSERT INTO Course VALUES (1, '高等数学', 4, '05003')
INSERT INTO Course VALUES (2, '数据库原理', 5, '05003')
INSERT INTO Course VALUES (3, '操作系统', 3, '05001')
INSERT INTO Course VALUES (4, '信息系统', 4, '05002')
GO

INSERT INTO SC VALUES ('08001', 1, 92)
INSERT INTO SC VALUES ('08001', 2, 85)
INSERT INTO SC VALUES ('08001', 3, 88)
INSERT INTO SC VALUES ('08002', 2, 90)
INSERT INTO SC VALUES ('08002', 3, 80)
GO

-- =============================================
-- 测试上述SQL是否成功
-- =============================================
SELECT * FROM Student
SELECT * FROM Teacher
SELECT * FROM Course
SELECT * FROM SC
GO

-- 1 查询CS系的学生的姓名
SELECT sname
FROM Student
WHERE sdept='CS';

-- 2 列出每门课程的编号及选修该门课程的学生人数，并按课程编号的升序排序（将学生人数列命名为scnt）
SELECT cno, COUNT(sno) AS scnt
FROM SC
GROUP BY cno
ORDER BY cno

-- 3 查询选修“数据库原理”的学生的学号、姓名和系别。
SELECT S.sno, S.sname, S.sdept
FROM Student S INNER JOIN SC ON	S.sno = SC.sno
               INNER JOIN Course C ON SC.cno = C.cno
WHERE C.cname='数据库原理';

-- 4 查询选修了任课教师为“李小强”的课程的学生的学号、姓名、系别、选修课程的课号、课程名称、学分和所得成绩。
SELECT S.sno, S.sname, S.sdept, C.cno, C.cname, C.ccredit, SC.score
FROM Student S INNER JOIN SC ON	S.sno = SC.sno
               INNER JOIN Course C ON SC.cno = C.cno
               INNER JOIN Teacher T ON C.tno = T.tno
WHERE T.tname='李小强';

-- 5 完成下列更新
INSERT INTO SC VALUES ('08001', 4, 90)

UPDATE SC
SET score = score + 1
WHERE sno IN (
  SELECT sno 
  FROM Student
  WHERE sname='张三');
  
DELETE FROM SC WHERE sno = '08002' AND cno = 3;

-- 6 查询选修了全部课程的学生的学号和姓名
SELECT S.sno, S.sname
FROM Student AS S
WHERE NOT EXISTS
	(SELECT *
	 FROM Course AS C
	 WHERE NOT EXISTS
		(SELECT *
		 FROM SC
		 WHERE SC.sno = S.sno AND SC.cno = C.cno)
	);