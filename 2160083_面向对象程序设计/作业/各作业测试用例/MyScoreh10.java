/**
 * 
 */
package com.huawei.classroom.student.h10;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
import com.huawei.classroom.context.*;

/**
 * @author Administrator
 *
 */
public class MyScoreh10 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh10(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {

		// TODO Auto-generated method stub

		Home10  home10 = new Home10();

		String method = "orderChar()";
		CTestCase t = new CTestCase(vo);
		t.setScore(20);
		t.setMethod(method);
		//h10
		t.setNum("1");
		t.setPredicate((Home10 h) ->"".equals(h.orderChar("")));
		t.test(home10);

		t.setNum("2");
		t.setPredicate((Home10 h) ->"a".equals(h.orderChar("aaaa")));
		t.test(home10);
		
		t.setNum("3");
		t.setPredicate((Home10 h) ->"abcd".equals(h.orderChar("abcd")));
		t.test(home10);
		
		t.setNum("4");
		t.setPredicate((Home10 h) ->"abcde".equals(h.orderChar("abcdeabcdeabcde")));
		t.test(home10);
		
		t.setNum("5");
		t.setPredicate((Home10 h) ->"a".equals(h.orderChar("a")));
		t.test(home10);
		 
	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh10("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
