-- =============================================
-- 创建数据库
-- =============================================
CREATE DATABASE EmpExam
GO

-- =============================================
-- 转到新建数据库
-- =============================================
USE EmpExam
GO

-- =============================================
-- 创建数据表
-- =============================================

-- ----------------------------------------
-- 部门 Department
-- ----------------------------------------
CREATE TABLE Dept
(
	deptNo		CHAR(2),			-- 部门编号
	deptName	VARCHAR(20)	NOT NULL,	-- 部门名称
	location	VARCHAR(10)	NOT NULL,	-- 所在城市
	CONSTRAINT Department_PK PRIMARY KEY(deptNo)	
)
GO

-- ----------------------------------------
-- 员工 Emp
-- ----------------------------------------
CREATE TABLE Emp
(
	empNo		CHAR(5),			-- 员工编号
	empName	VARCHAR(10)	NOT NULL,	-- 员工姓名
	deptNo		CHAR(2),			-- 所在部门
	CONSTRAINT Emp_PK PRIMARY KEY(empNo),
	CONSTRAINT Emp_Dept_FK FOREIGN KEY(deptNo)
		 REFERENCES Dept(deptNo)
)
GO

-- ----------------------------------------
-- 项目 Proj
-- ----------------------------------------
CREATE TABLE Proj
(
	projNo	CHAR(2),			-- 项目编号
	projName	VARCHAR(20)	NOT NULL,	-- 项目名称
	budget		INT		NOT NULL,	-- 项目预算
	CONSTRAINT Proj_PK PRIMARY KEY(projNo)
)
GO

-- ----------------------------------------
-- 承担 Works [关系]
-- ----------------------------------------
CREATE TABLE Works
(
	empNo		CHAR(5),			-- 员工编号
	projNo	CHAR(2),			-- 项目编号
	job		VARCHAR(10),			-- 职务
	enterDate	SMALLDATETIME  NOT NULL,	-- 加入时间
	CONSTRAINT Works_PK PRIMARY KEY(empNo, projNo),
	CONSTRAINT Works_Emp_FK FOREIGN KEY(empNo)
		REFERENCES Emp(empNo),
	CONSTRAINT Works_Proj_FK FOREIGN KEY(projNo)
		REFERENCES Proj(projNo)
)
GO

-- =============================================
-- 插入数据
-- =============================================

INSERT INTO Dept VALUES ('D1', '开发部', '天津')
INSERT INTO Dept VALUES ('D2', '财务部', '北京')
INSERT INTO Dept VALUES ('D3', '市场部', '广东')
INSERT INTO Dept VALUES ('D4', '信息技术部', '天津')
GO

INSERT INTO Emp VALUES ('02581', '徐唱', 'D2')
INSERT INTO Emp VALUES ('09031', '李静', 'D2')
INSERT INTO Emp VALUES ('10102', '王文刚', 'D3')
INSERT INTO Emp VALUES ('18316', '冯新', 'D1')
INSERT INTO Emp VALUES ('25348', '张风', 'D3')
INSERT INTO Emp VALUES ('28559', '刘国风', 'D1')
INSERT INTO Emp VALUES ('29346', '赵东生', 'D2')
INSERT INTO Emp VALUES ('40000', '刘欢', 'D2')
INSERT INTO Emp VALUES ('40001', '张亮', 'D2')
GO

INSERT INTO Proj VALUES ('P1', '网络布线', 135000)
INSERT INTO Proj VALUES ('P2', '软件升级', 95000)
INSERT INTO Proj VALUES ('P3', '系统开发', 185600)
INSERT INTO Proj VALUES ('P4', '计划项目1', 20000)
GO

INSERT INTO Works VALUES ('02581', 'P3', '分析员', '2008-10-15')
INSERT INTO Works VALUES ('09031', 'P1', '管理员', '2008-04-15')
INSERT INTO Works VALUES ('09031', 'P3', '职员', '2007-11-15')
INSERT INTO Works VALUES ('10102', 'P1', '分析员', '2007-01-10')
INSERT INTO Works VALUES ('10102', 'P3', '管理员', '2009-01-01')
INSERT INTO Works VALUES ('18316', 'P2', '职员', '2008-02-15')
INSERT INTO Works VALUES ('25348', 'P2', NULL, '2008-06-01')
INSERT INTO Works VALUES ('28559', 'P1', NULL, '2008-08-01')
INSERT INTO Works VALUES ('28559', 'P2', '职员', '2009-02-01')
INSERT INTO Works VALUES ('28559', 'P3', '职员', '2008-05-07')
INSERT INTO Works VALUES ('29346', 'P1', '职员', '2008-01-04')
INSERT INTO Works VALUES ('29346', 'P3', '职员', '2009-04-04')
GO

-- =============================================
-- 列出数据：测试上述SQL是否成功
-- =============================================

SELECT * FROM Dept
SELECT * FROM Emp
SELECT * FROM Proj
SELECT * FROM Works
GO


-- 1
-- 单表查询
SELECT deptName
FROM Dept
WHERE location='天津'

-- 2
-- 分组查询
SELECT projNo, COUNT(*) AS empCnt
FROM Works
GROUP BY projNo
ORDER BY projNo

-- 3
-- 连接查询 两个表
SELECT empNo, job
FROM Proj P INNER JOIN Works W ON
	P.projNo = W.projNo
WHERE projName='系统开发'

-- 4
-- 连接查询 4个表
SELECT W.empNo, W.enterDate
FROM Proj P INNER JOIN Works W ON P.projNo = W.projNo
                      INNER JOIN Emp E ON W.empNo = E.empNo
                      INNER JOIN Dept D ON E.deptNo = D.deptNo
WHERE P.projName='网络布线' AND D.deptName='财务部'

-- 5 
SELECT empNo, empName
FROM Emp E
WHERE NOT EXISTS ( 
	SELECT *
	FROM Works W
	WHERE W.empNo = E.empNo
)
-- 或
SELECT empNo, empName
FROM Emp E
WHERE empNo NOT IN ( 
	SELECT empNo
	FROM Works W
	WHERE W.empNo = E.empNo
)

-- 3
SELECT Dept.deptNo, Dept.deptName
FROM Dept
WHERE Dept.deptNo IN (
SELECT Emp.deptNo
FROM Emp
GROUP BY Emp.deptNo
HAVING COUNT(*) > 4)

SELECT E.empNo, E.empName
FROM Emp AS E
WHERE NOT EXISTS
	(SELECT *
	 FROM Proj AS P
	 WHERE NOT EXISTS
		(SELECT *
		 FROM Works AS W
		 WHERE W.empNo = E.empNo AND W.projNo = P.projNo)
	);