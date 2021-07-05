/**
 * 
 */
package com.huawei.classroom.student.h09;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
import com.huawei.classroom.context.*;

/**
 * @author Administrator
 *
 */
public class MyScoreh09 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh09(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {

		// TODO Auto-generated method stub

		Home09 home06 = new Home09();

		String method = "getDistinctCharCount";
		CTestCase t = new CTestCase(vo);
		t.setScore(10);
		t.setMethod(method);
		t.setNum("1");
		t.setPredicate((Home09 h) -> h.getDistinctCharCount("") == 0);
		t.test(home06);

		t.setNum("2");
		t.setPredicate((Home09 h) -> h.getDistinctCharCount("天天天") == 1);
		t.test(home06);

		t.setNum("3");
		t.setPredicate((Home09 h) -> h.getDistinctCharCount("天津市天大") == 4);
		t.test(home06);

		method = "getFrequentChar";
		t.setMethod(method);
		t.setNum("1");
		t.setPredicate((Home09 h) -> 'b' == h.getFrequentChar("abcdabcb"));
		t.test(home06);

		t.setNum("2");
		t.setPredicate((Home09 h) -> 'z' == h.getFrequentChar("abcdzz"));
		t.test(home06);

		method = "getFrequentWord";
		t.setMethod(method);
		t.setNum("1");
		t.setPredicate((Home09 h) -> "ef".equals(h.getFrequentWord("abcdefabefef")));
		t.test(home06);

		t.setNum("2");
		t.setPredicate((Home09 h) -> "zz".equals(h.getFrequentWord("azzza")));
		t.test(home06);

		t.setNum("3");
		t.setPredicate((Home09 h) -> " c".equals(h.getFrequentWord(" a b c c")));
		t.test(home06);

		method = "zipStringBufer";
		t.setMethod(method);
		t.setNum("1");
		t.setPredicate((Home09 h) -> {
			StringBuffer buf = new StringBuffer(" e f c ");
			h.zipStringBufer(buf);
			return "efc".equals(buf.toString());
		});
		t.test(home06);

		t.setMethod(method);
		t.setNum("2");
		t.setPredicate((Home09 h) -> {
			StringBuffer buf = new StringBuffer("   ");
			h.zipStringBufer(buf);
			return "".equals(buf.toString());
		});
		t.test(home06);
	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh09("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
