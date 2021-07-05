/**
 * 
 */
package com.huawei.classroom.student.h53;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
/**
 * @author Administrator
 *
 */
public class MyScoreh53 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh53(String id) {
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
		
		RabbitCount home = new RabbitCount();		
		t.setPredicate((RabbitCount h)->{
			int  result=h.getLivingRabbit(3, 1700);
			return Math.abs(1-result*1.0/(488568))<0.3;
		});
		t.test(home);	
	}
	public static void main(String[] args) {
		QuestionTempVo vo=new QuestionTempVo();
		try {
			new MyScoreh53("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
