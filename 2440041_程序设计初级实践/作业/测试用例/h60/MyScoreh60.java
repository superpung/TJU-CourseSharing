/**
 * 
 */
package com.huawei.classroom.student.h60;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;

/**
 * @author Administrator
 *
 */
public class MyScoreh60 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh60(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {

		// TODO Auto-generated method stub
		String method = "case 1";
		CTestCase t = new CTestCase(vo);
		t.setScore(40);
		t.setMethod(method);
		t.setNum("1");
		String ip = "127.0.0.1";
		int port = 7071;
		String passwordFile = "D:/java_test/sandbox/read/2021_h60_user.txt";

		ChatServer server = new ChatServer(port, passwordFile);
		// 1 服务器启动监听
		server.startListen();
		ChatClient a = new ChatClient(ip, port);
		ChatClient b = new ChatClient(ip, port);
		ChatClient c = new ChatClient(ip, port);
		t.setPredicate((ChatServer h) -> {
			try {
				if (!a.login("a", "a")) {
					System.out.println("pass1");
				}
				if (b.login("b", "2")) {
					System.out.println("pass2");
				}
				if (c.login("c", "3")) {
					System.out.println("pass3");
				}
				return true;
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return false;
			}

		});
		t.test(server);

		method = "case 2";
		t.setScore(30);
		t.setNum("2");
		t.setMethod(method);
		t.setPredicate((ChatServer h) -> {
			try {
				String s = "";
				for (int i = 0; i < 5; i++) {
					s = String.valueOf(i);
					b.speak(s);
					try {
						Thread.sleep(100);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					String sa = a.read();
					String sb = b.read();
					String sc = c.read();
					if (null == sa && s.equals(sb) && s.equals(sc)) {
						// System.out.println("pass " + i);
					} else {
						return false;
					}
				}
				return true;
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return false;
			}
		});
		t.test(server);

		method = "case 3";
		t.setNum("3");
		t.setMethod(method);
		t.setScore(30);
		b.logout();
		String s = "a";

		c.speak(s);
		Thread.sleep(100);

		String sa = a.read();
		String sb = b.read();
		String sc = c.read();
		vo.apendDetail(" case3: sa=["+sa+"]\tsb=["+sb+"]\tsc=["+sc+"]");
		t.setPredicate((ChatServer h) -> {
			if (null == sa && null == sb && s.equalsIgnoreCase(sc)) {
				return true;
			} else {
				return false;
			}
		});
		t.test(server);
	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh60("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
