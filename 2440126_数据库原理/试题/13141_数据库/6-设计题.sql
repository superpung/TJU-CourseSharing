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
	deptNo		CHAR(2),			-- 编号
	deptName	VARCHAR(20)	NOT NULL,	-- 名称
	CONSTRAINT Department_PK PRIMARY KEY(deptNo)	
)
GO

-- ----------------------------------------
-- 员工 Emp
-- ----------------------------------------
CREATE TABLE Emp
(
	empNo		CHAR(5),			-- 编号
	empName	VARCHAR(10)	NOT NULL,	-- 姓名
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
	projNo	CHAR(2),			-- 编号
	projName	VARCHAR(20)	NOT NULL,	-- 名称
	budget		INT		NOT NULL,	-- 预算
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

INSERT INTO Dept VALUES ('D1', '开发部')
INSERT INTO Dept VALUES ('D2', '市场部')
INSERT INTO Dept VALUES ('D3', '财务部')
GO

INSERT INTO Emp VALUES ('02581', '徐唱', 'D2')
INSERT INTO Emp VALUES ('09031', '李静', 'D2')
INSERT INTO Emp VALUES ('10102', '王文刚', 'D3')
INSERT INTO Emp VALUES ('18316', '冯新', 'D1')
INSERT INTO Emp VALUES ('28559', '刘国风', 'D1')
GO

INSERT INTO Proj VALUES ('P1', '系统升级', 135000)
INSERT INTO Proj VALUES ('P2', '软件开发', 185600)
GO

INSERT INTO Works VALUES ('18316', 'P1', '组长')
INSERT INTO Works VALUES ('10102', 'P1', '组员')
INSERT INTO Works VALUES ('28559', 'P2', '组长')
INSERT INTO Works VALUES ('18316', 'P2', '组员')
INSERT INTO Works VALUES ('09031', 'P2', '组员')
GO

-- =============================================
-- 列出数据：测试上述SQL是否成功
-- =============================================

SELECT * FROM Dept
SELECT * FROM Emp
SELECT * FROM Proj
SELECT * FROM Works
GO
