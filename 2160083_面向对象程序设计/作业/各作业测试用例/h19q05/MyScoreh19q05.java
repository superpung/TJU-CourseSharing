package com.huawei.classroom.student.h19.q05;

import java.util.Arrays;
import java.util.List;
import java.util.Set;


import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;

/**
 * @author Administrator
 *
 */
public class MyScoreh19q05 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh19q05(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {
		 //h10.q05
		String fileName = "D:\\java_test\\sandbox\\read\\h19_score.txt";
		StudentUtil util = new StudentUtil();	
		String method = "sort";
		CTestCase t = new CTestCase(vo);
		t.setScore(20);
		t.setMethod(method);
		t.setPredicate((StudentUtil h) -> {
			List<String> result=Arrays.asList("zhangsan","lisi","wangwu","zhaoliu");
			List<String>  list = util.sort(fileName); 
			return result.equals(list); 
		});
		t.test(util);

	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh19q05("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
