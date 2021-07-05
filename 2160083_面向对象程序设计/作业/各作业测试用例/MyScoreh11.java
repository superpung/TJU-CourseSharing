/**
 * 
 */
package com.huawei.classroom.student.h11;

import com.huawei.classroom.teacher.MyUtil;
import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;

/**
 * @author Administrator
 *
 */
public class MyScoreh11 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh11(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {

		// TODO Auto-generated method stub

		Home11 home11 = new Home11();

		String content = "炸鸡,可乐,啤酒;薯片,啤酒,炸鸡;啤酒,雪碧,炸鸡;可乐,牙膏;可乐,面包;啤酒,面包;可乐,榨菜;啤酒,雪碧;洗手液";

		String method = content;
		CTestCase t = new CTestCase(vo);
		t.setScore(50);
		t.setMethod(method);
		t.setNum("1");
		t.setPredicate((Home11 h) -> {
			String result = h.getFrequentItem("炸鸡,可乐,啤酒;薯片,啤酒,炸鸡;啤酒,雪碧,炸鸡;可乐,牙膏;可乐,面包;啤酒,面包;可乐,榨菜;啤酒,雪碧;洗手液");
			result = MyUtil.sortStr(result);
			return MyUtil.sortStr("啤酒,炸鸡").equals(result);
		});
		t.test(home11);

		content = "2,3,1;1,5,7;7,4,2;3,1;2,1,8;1,2,9;6,2,1;1,2,4;9,4,1";
		method = content;
		t = new CTestCase(vo);
		t.setScore(50);
		t.setMethod(method);
		t.setNum("2");
		t.setPredicate((Home11 h) -> {
			String result = h.getFrequentItem("2,3,1;1,5,7;7,4,2;3,1;2,1,8;1,2,9;6,2,1;1,2,4;9,4,1");
			result = MyUtil.sortStr(result);
			return MyUtil.sortStr("1,2").equals(result);
		});
		t.test(home11);

	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh11("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
