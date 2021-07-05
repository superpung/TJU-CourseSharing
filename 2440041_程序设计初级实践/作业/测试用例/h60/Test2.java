/**
 * 
 */
package com.huawei.classroom.student.h60;

/**
 * @author Administrator
 *
 */
public class Test2 {
 
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 在ChatServer,ChatClient中增加适当代码，并增加适当的类，完成一个简单的聊天室
		// user.txt中存放了所有用户的用户名和口令 用\t分割
		String ip = "127.0.0.1";
		int port = 7071;
		String passwordFile = "XXXX/2021_h60_user.txt";
		ChatServer  server;
		try {
			server = new ChatServer (port, passwordFile);

			// 1 服务器启动监听
			server.startListen();
			ChatClient  a = new ChatClient (ip, port);
			ChatClient  b = new ChatClient (ip, port);
			ChatClient  c = new ChatClient (ip, port);

			// 2 客户1 登录成功
			if (!a.login("a", "a")) {
				System.out.println("pass1");
			}

			// 3 客户2 登录成功
			if (b.login("b", "2")) {
				System.out.println("pass2");
			}

			// 3 客户3 登录失败
			if (c.login("c", "3")) {
				System.out.println("pass3");
			}
			String s="";
			for(int i=0;i<10;i++) {
				s=String.valueOf(i);
				b.speak(s);
				 Thread.sleep(100);
				String sa=a.read();
				String sb=b.read();
				String sc=c.read();
				
				if(null==sa&&s.equals(sb)&&s.equals(sc)) {
					System.out.println("pass "+i);
				}else {
					System.out.println("fail"+i);
				}
			}
			 
			b.logout();
			c.speak(s);
			 Thread.sleep(100);
			String sa=a.read();
			String sb=b.read();
			String sc=c.read();
			
			
			 
			if (null==sa &&null == sb&& s.equalsIgnoreCase(sc)) {
				System.out.println("pass5");
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
