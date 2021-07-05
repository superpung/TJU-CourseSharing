-- =============================================
-- 转到新建数据库
-- =============================================
USE tempdb
GO

DROP TABLE [Borrow]
DROP TABLE [Book]
DROP TABLE [Category]
DROP TABLE [Reader]

-- =============================================
-- 创建数据表
-- =============================================

-- ----------------------------------------
-- 图书类别
-- ----------------------------------------
CREATE TABLE [Category]
(
	[id]		CHAR(2),
	[name]		VARCHAR(20)	NOT NULL,		-- 图书类别名称
	CONSTRAINT [Category_PK] PRIMARY KEY([id])
)
GO

-- ----------------------------------------
-- 图书
-- ----------------------------------------
CREATE TABLE [Book]
(
	[id]		CHAR(2),	
	[title]		VARCHAR(80)	NOT NULL,		-- 书名
	[author]	VARCHAR(80)	NOT NULL,		-- 作者
	[publisher]	VARCHAR(80)	NOT NULL,
	[pubDate]	DATETIME	NOT NULL,		-- 出版日期
	[copyCount]	INT		NOT NULL,		-- 副本数量
	[categoryId]	CHAR(2)	NOT NULL,
	CONSTRAINT [Book_PK] PRIMARY KEY([id]),
	CONSTRAINT [Book_Category_FK] FOREIGN KEY([categoryId]) REFERENCES [Category]([id])
)
GO

-- ----------------------------------------
-- 读者
-- ----------------------------------------
CREATE TABLE [Reader]
(
	[id]		CHAR(2),
	[name]		VARCHAR(20)	NOT NULL,		-- 读者姓名
	[gender]	CHAR(2)	NOT NULL,		-- 性别
	[birthday]	DATETIME	NOT NULL,		-- 出生日期
	[tel]		VARCHAR(20)	NOT NULL,		-- 电话号码
	CONSTRAINT [Reader_PK] PRIMARY KEY([id])
)
GO

-- ----------------------------------------
-- 借阅 关系
-- ----------------------------------------
CREATE TABLE [Borrow]
(
	[readerId]	CHAR(2),
	[bookId]	CHAR(2),
	[borrowDate]	DATETIME	NOT NULL,		-- 借书日期
	[returnDate]	DATETIME,				-- 还书日期
	CONSTRAINT [Borrow_PK] PRIMARY KEY([bookId], [readerId]),
	CONSTRAINT [Borrow_Book_FK] FOREIGN KEY([bookId]) REFERENCES [Book]([id]),
	CONSTRAINT [Borrow_Reader_FK] FOREIGN KEY([readerId]) REFERENCES [Reader]([id])
)
GO

-- =============================================
-- 插入样本数据
-- =============================================

INSERT INTO [Category] VALUES ('C1', '科技')
INSERT INTO [Category] VALUES ('C2', '文学')

INSERT INTO [Book] VALUES ('B1', '时间简史', '霍金', '甲', '2008-10-01', 5,'C1')
INSERT INTO [Book] VALUES ('B2', '三国演义', '罗贯中', '乙', '2009-06-01', 10,'C2')

INSERT INTO [Reader] VALUES ('R1', '李勇', '男', '1991-02-19',	'13811122233')
INSERT INTO [Reader] VALUES ('R2', '刘晨', '女', '1990-01-09',	'13911122233')

INSERT INTO [Borrow] VALUES ('R1', 'B1', '2010-06-21', NULL)
INSERT INTO [Borrow] VALUES ('R1', 'B2', '2010-06-21', NULL)
INSERT INTO [Borrow] VALUES ('R2', 'B2', '2010-06-21', NULL)
GO

-- =============================================
-- 测试上述SQL是否成功
-- =============================================

SELECT * FROM [Category]
SELECT * FROM [Book]
SELECT * FROM [Reader]
SELECT * FROM [Borrow]
GO
