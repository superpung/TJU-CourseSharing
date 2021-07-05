/**
 * 
 */
package com.huawei.classroom.student.h51;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
/**
 * @author Administrator
 *
 */
public class MyScoreh51 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh51(String id) {
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
		
		HongBao home = new HongBao();		
		t.setPredicate((HongBao h)->{
			double[] result=h.getHongbao(0.03, 3);
			double[] target= {0.01,0.01,0.01};
			return super.eq(result, target);
		});
		t.test(home);				
	}
	public static void main(String[] args) {
		QuestionTempVo vo=new QuestionTempVo();
		try {
			new MyScoreh51("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
