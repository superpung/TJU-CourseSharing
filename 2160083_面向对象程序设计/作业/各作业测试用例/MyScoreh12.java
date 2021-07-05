/**
 * 
 */
package com.huawei.classroom.student.h12;

import java.util.HashSet;
import java.util.Set;

import com.huawei.classroom.teacher.MyUtil;
import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;

/**
 * @author Administrator
 *
 */
public class MyScoreh12 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh12(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {

		// TODO Auto-generated method stub

		Home12 home12 = new Home12();

	 

		String method = "getFrequentItem";
		CTestCase t = new CTestCase(vo);
		t.setScore(30);
		t.setMethod(method);
		t.setNum("1");
		t.setPredicate((Home12 h) -> {
			Set<String> result = h.getFrequentItem("a,b,c,d,e,f;a,e,b,c,g,k;s,w,q,a,c,b;z,l,m,a",1);
			Set<String> right=new HashSet<String>(); 
			right.add("a");
			return right.equals(result);
		});
		t.test(home12);
		 
		t.setMethod(method);
		t.setNum("2");
		t.setPredicate((Home12 h) -> {
			Set<String> result = h.getFrequentItem("1,2,3;5,2,1;6,1,2;8,9,7",2);
			Set<String> right=new HashSet<String>(); 
			right.add("1");
			right.add("2");
			return right.equals(result);
		});
		t.test(home12);
		 
		t = new CTestCase(vo);
		t.setMethod(method);
		t.setScore(40);
		t.setNum("3");
		t.setPredicate((Home12 h) -> {
			Set<String> result = h.getFrequentItem("9,0,1,2,3,4;2,3,4,8,1,0;1,4,6,2,3,7,8;1,2,3,4,p,q;1,2,3,4,s,w;s,e,r,f,p;7,8,9,0,e",4);
			Set<String> right=new HashSet<String>(); 
			right.add("1");
			right.add("2");
			right.add("3");
			right.add("4");
			return right.equals(result);
		});
		t.test(home12);

	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh12("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
