/**
 * 
 */
package com.huawei.classroom.student.h59;

import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
/**
 * @author Administrator
 *
 */
public class MyScoreh59 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh59(String id) {
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
		ReactionTools home = new ReactionTools();		
		t.setPredicate((ReactionTools h)->{

			Set<String> init=new HashSet<String>();
			init.add("HCl");
			init.add("NaOH");
			Set<String> result=h.findAllComponents("D:/java_test/sandbox/read/test_reactions.txt", init);
			Set<String> target=new HashSet<String>();
			target.add("HCl");
			target.add("NaOH");
			target.add("H+");
			target.add("Cl-");
			target.add("Na+");
			target.add("OH-");
			target.add("H2O");
			target.add("NaCl");
			target.add("H2");
			target.add("O2");

			return  (target.equals(result));
		});
		t.test(home);
		 
			
	}
	public static void main(String[] args) {
		QuestionTempVo vo=new QuestionTempVo();
		try {
			new MyScoreh59("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
