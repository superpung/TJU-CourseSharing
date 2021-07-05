/**
 * 
 */
package com.huawei.classroom.student.h55;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
/**
 * @author Administrator
 *
 */
public class MyScoreh55 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh55(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {
		
		// TODO Auto-generated method stub
		String method="case 1";		
		CTestCase t=new CTestCase(vo);
		t.setScore(100);
		t.setMethod(method);
		PoetryAnalysis home = new PoetryAnalysis();		
		t.setPredicate((PoetryAnalysis h)->{
			String chars="笑;泪;哭;乐";
			 h.analysis("XXXX/dufu.txt", chars);
			 return true;
		});
		t.test(home);
		 
			
	}
	public static void main(String[] args) {
		QuestionTempVo vo=new QuestionTempVo();
		try {
			new MyScoreh55("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
