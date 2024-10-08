# 图像处理

## 21221 学期 李亮

### 简介

学习图像处理的基本概念，通过使用 Python、MATLAB 工具进行图像处理实验。主要的学习内容有：数字图像基础、空间域图像增强、频率域图像增强、图像分割与图像复原等内容。

### 平时

课上听课为主，会提问但不会点名。较少签到，老师可能只是想混个眼熟。课下没有纸质作业全是实验。实验难度稍大，需要提前学习好工具的使用（Python及其图像处理库/MATLAB），完成实验时间稍长。作业通过天大网盘提交，并留有2~3周的完成时间，你甚至可以看到提交早的同学的作业内容。

大概有以下五项作业供参考：

作业一：
* 使用 matlab/Python 写一个函数，`img = generateFigure(imgW,imgH)`，其作用为产生一幅的彩色图像，图像中用红色显示 `[0,2*pi]` 的正弦波，用绿色显示`[0,2*pi]`的余弦波，蓝色显示`[0,2*pi]`的y=x^2图像。
* 不使用 for 循环，实现bilinear interpolation

作业二：
* 实现直方图均衡化
* 实现直方图规定化（直方图匹配）并完成风格迁移

作业三：
* 实现均值滤波器，包括：算术均值滤波器、几何均值滤波器、谐波、逆谐波滤波器；
* 实现统计排序滤波器，包括：中值、最大值、最小值、中点、修正后的阿尔法均值滤波器。
* 实现自适应滤波器。

作业四：
* 实现最小二乘法、RANSAC法、霍夫变换法
  * 对于直线方程`y=ax+b`，生成一系列纵坐标符合高斯分布的点，再人工加入一系列的 outlier，使用上述三种方法拟合一条直线
  * 找到一幅实际图像（较简单的），使用一阶导数或二阶导数找出边缘点，使用上述三种方法，找到其中的直线

作业五（已布置但最后取消了）：
* 使用 matla b实现 shape context，并与 opencv 版本进行对比，进行形状搜索实验。
* 参考给定论文运行代码并用自己图像进行测试


### 考试

1~2人组队，老师给出一些备选题目以及对应的参考文献，每队挑选一项进行完成并答辩。作业难度稍大，需要具有英文文献阅读能力以及动手复现算法的能力。部分同学会有老师提问环节（根据老师心情），有时候老师会追着问，需对自己的内容做好准备（以及心理准备）。

- 形式：完成大作业项目+答辩
- 时间：2节课
- 题型：自主选题

备选题目：
1. Edge-Preserving Image Smoothing
2. Image stitching
3. Dehazing & Low Light Enhancement
4. Superpixel Segmentation

### 成绩

80~90左右

### 评价

很少人选课，大概 20 几个。诺大教室一般也就 10+ 左右同学听课。对于选修课花费的时间和精力较多，少人选也难怪。

### 经验

少人的课会有一些特别的地方。平时注意按时上课，老师都是混脸熟给平时分的。作业不会做可以参考网上相似教程，或 _卷王_ 早早写好的作业，你会有相关思路（注意不要过度参考身边同学的作业）。答辩时认真准备，尽力完成任务，老师不会为难你。但是如果部分内容讲不清楚老师可能会对你更**照顾**一些了。
