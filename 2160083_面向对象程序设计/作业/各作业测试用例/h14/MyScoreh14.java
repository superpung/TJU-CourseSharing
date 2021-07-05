/**
 * 
 */
package com.huawei.classroom.student.h14;

import java.io.File;
import java.util.HashSet;
import java.util.Set;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;

/**
 * @author Administrator
 *
 */
public class MyScoreh14 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh14(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {

		String studentListFileName = "D:\\java_test\\sandbox\\read\\students_test.txt";
		String picDir = "D:\\java_test\\sandbox\\read\\pic_test\\";
		String targetDir = "D:\\java_test\\sandbox\\write\\target_test\\";
		MyTools myTools = new MyTools();

		String method = "copyToTargetDirAndReturnNoExist";
		
		CTestCase t = new CTestCase(vo);
		File file=new File(targetDir);
		if(file.exists()) {
			deleteDir(file);
		}
		t.setScore(100);
		t.setMethod(method);
		t.setNum("1");
		Set<String> test=new HashSet<String>();
		test.add("3016218014");
		test.add("3016218015");
		Set<String> nopicsIds = myTools.copyToTargetDirAndReturnNoExist(studentListFileName,picDir,targetDir);
		t.setPredicate((Set<String> s1) -> {
			return new File("D:\\java_test\\sandbox\\write\\target_test/1/3016218011_zhaoliu.jpg").exists()
			&&new File("D:\\java_test\\sandbox\\write\\target_test/3/3016218012_wangwu.jpg").exists()
			&&new File("D:\\java_test\\sandbox\\write\\target_test/3/3016218013_zhangsan.jpg").exists()
			&&new File("D:\\java_test\\sandbox\\write\\target_test/3/3016218013_zhangsan.jpg").exists()
			&&super.eq(test, nopicsIds);
		});
		t.test(nopicsIds);
	}
	public  void deleteDir(File file) {
		// 如果file代表文件，就删除该文件
		if (file.isFile()) {
			file.delete();
			return;
		}
		// 如果file代表目录，先删除目录下的所有子目录和文件
		File[] lists = file.listFiles();
		for (int i = 0; i < lists.length; i++) {
			deleteDir(lists[i]); // 递归删除当前目录下的所有子目录和文件
		}
		// 最后删除当前目录
		file.delete();
	}
	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh14("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
