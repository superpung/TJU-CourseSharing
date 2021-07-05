/**
 * 
 */
package com.huawei.classroom.student.h58;

import java.util.Map;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
/**
 * @author Administrator
 *
 */
public class MyScoreh58 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh58(String id) {
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
		VoteRecord home = new VoteRecord();		
		t.setPredicate((VoteRecord h)->{
			Map<String,Integer> map= h.calcRecording("D:/java_test/sandbox/read/vote_detail2.txt");
			int ta=map.get("ta");
			int tb=map.get("tb");
			int tc=map.get("tc");
			return super.aeq(ta, 4169, 0.3)&&super.aeq(tb, 4253, 0.3)&&super.aeq(tc, 8297, 0.3);
			//return super.aeq(ta, 7828, 0.3)&&super.aeq(tb, 7987, 0.3)&&super.aeq(tc, 15711, 0.3);
		});
		t.test(home);
		 
	 
	}
	public static void main(String[] args) {
		QuestionTempVo vo=new QuestionTempVo();
		try {
			new MyScoreh58("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
