-- =============================================
-- 创建数据库
-- =============================================

CREATE DATABASE StudentCourseTeacher;

-- =============================================
-- 转到新建数据库
-- =============================================
USE StudentCourseTeacher;

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
	sgender		CHAR(2)		NOT NULL,
	sbirth		DATETIME	NOT NULL,
	sdept		CHAR(2)		NOT NULL,
	CONSTRAINT Student_PK PRIMARY KEY(sno)
);

-- ----------------------------------------
-- 教师
-- ----------------------------------------
CREATE TABLE Teacher
(
	tno			CHAR(5),
	tname		VARCHAR(10)	NOT NULL,
	tdept		CHAR(2)		NOT NULL,
	CONSTRAINT Teacher_PK PRIMARY KEY(tno)
);

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
);

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
);


-- =============================================
-- 插入样本数据
-- =============================================

INSERT INTO Student VALUES ('08001', '张三', '男', '1988-02-19', 'CS');
INSERT INTO Student VALUES ('08002', '李四', '女', '1989-01-09', 'CS');
INSERT INTO Student VALUES ('08003', '王五', '女', '1990-12-08', 'CE');
INSERT INTO Student VALUES ('08004', '赵六', '男', '1989-08-30', 'IS');

INSERT INTO Teacher VALUES ('05001', '张小明', 'CS');
INSERT INTO Teacher VALUES ('05002', '王小华', 'IS');
INSERT INTO Teacher VALUES ('05003', '李小强', 'CS');
INSERT INTO Teacher VALUES ('05004', '赵小兰', 'CE');

INSERT INTO Course VALUES (1, '高等数学', 4, '05003');
INSERT INTO Course VALUES (2, '数据库原理', 5, '05003');
INSERT INTO Course VALUES (3, '操作系统', 3, '05001');
INSERT INTO Course VALUES (4, '信息系统', 4, '05002');

INSERT INTO SC VALUES ('08001', 1, 92);
INSERT INTO SC VALUES ('08001', 2, 85);
INSERT INTO SC VALUES ('08001', 3, 88);
INSERT INTO SC VALUES ('08002', 2, 90);
INSERT INTO SC VALUES ('08002', 3, 80);

-- =============================================
-- 测试上述SQL是否成功
-- =============================================
SELECT * FROM Student;
SELECT * FROM Teacher;
SELECT * FROM Course;
SELECT * FROM SC;

-- 1 列出平均成绩大于等于85的课程的编号、名称及平均成绩，并按课程编号的升序排序（将平均成绩列命名为avg_score）。（5分）
SELECT cno, AVG(score) AS avg_score
FROM SC
GROUP BY cno
HAVING AVG(score) >= 85
ORDER BY cno

-- 2 查询选修“数据库原理”的学生的学号、姓名和系别。（5分）
SELECT S.sno, S.sname, S.sdept
FROM Student S INNER JOIN SC ON	S.sno = SC.sno
               INNER JOIN Course C ON SC.cno = C.cno
WHERE C.cname='数据库原理';


-- 5 完成下列更新
INSERT INTO Course VALUES (5, '知识工程', 1, '05002')

UPDATE Course
SET ccredit = ccredit * 2.5
WHERE cname = '知识工程';
  
DELETE FROM Course WHERE tno =
(SELECT tno FROM Teacher WHERE tname = '赵小兰');

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