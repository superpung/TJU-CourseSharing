/**
 * 
 */
package com.huawei.classroom.student.h62;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.SimpleDateFormat;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;

/**
 * @author Administrator
 *
 */
public class MyScoreh62 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh62(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {
		
			String method = "case 1";
			CTestCase t = new CTestCase(vo);
			t.setScore(40);
			t.setMethod(method);

			String passwordFile = "D:/java_test/sandbox/read/h62_my_user.txt";
			String remoteHome = "D:/java_test/sandbox/write/h62/";
			int port = 1999;
			clearDir(remoteHome);
			File home = new File(remoteHome + "a/");
			if (!home.exists()) {
				home.mkdirs();
			}

			MyDeamonConfigVo config = new MyDeamonConfigVo();
			config.setRoot(remoteHome);
			config.setPort(port);
			config.setPasswordFile(passwordFile);
			MyDaemon deamon = new MyDaemon(config);
			deamon.start();

			MyHost host = new MyHost();
			host.setIp("127.0.0.1");
			host.setPort(config.getPort());
			host.setUsername("cc");
			host.setPassword("33");

			MyRemoteFile file1 = new MyRemoteFile(host, "/");
			t.setPredicate((MyRemoteFile h) -> {
				try {

					MyRemoteFile[] children = h.dirByNameAsc();

					return (children.length==1)&&(children[0].isDirectory())&&(!children[0].isFile())&&("/a/".equals(children[0].getPathFileName()));

				} catch (Exception e) {
					this.log(e.getMessage());
					vo.apendDetail(e.getMessage());
					return false;
				}
			});
			t.test(file1);

			
			method = "case 2";
			t.setMethod(method);
			t.setScore(30);
			MyRemoteFile file2 = new MyRemoteFile(host, "/a/test2.txt");
			t.setPredicate((MyRemoteFile h) -> {
				try {
					String content = "abc";
					h.writeByBytes(content.getBytes("UTF-8"));
					MyRemoteFile file3 = new MyRemoteFile(host, "/a/test2.txt");
					return file3.length() == content.getBytes("UTF-8").length;
				} catch (Exception e) {
					this.log(e.getMessage());
					vo.apendDetail(e.getMessage());
					return false;
				}
			});
			t.test(file2);
			
			method = "case 3";
			t.setMethod(method);
			t.setScore(30);
			MyRemoteFile file4 = new MyRemoteFile(host, "/a/test1.txt");
			file4.writeByBytes("abc".getBytes());
			MyRemoteFile file5 = new MyRemoteFile(host, "/a/");
			t.setPredicate((MyRemoteFile h) -> {
				try {
					MyRemoteFile[] children = h.dirByNameAsc();
					MyRemoteFile c0 = children[0];
					MyRemoteFile c1 = children[1];
					return c0.getPathFileName().equals("/a/test1.txt") && c1.getPathFileName().equals("/a/test2.txt");
				} catch (Exception e) {
					this.log(e.getMessage());
					vo.apendDetail(e.getMessage());
					return false;
				}
			});
			t.test(file5);

	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh62("").doEval(vo);
			System.out.println("ok");
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void clearDir(String homeDir) throws IOException {
		deleteFile(homeDir, false);
	}

	public static void deleteFile(String home, boolean delHome) throws IOException {
		File file = new File(home);
		if (!file.exists()) {
			return;
		}
		if (file.isFile()) {
			file.delete();
			return;
		}
		if (file.isDirectory()) {
			File[] files = file.listFiles();
			for (int i = 0; i < files.length; i++) {
				deleteFile(files[i].getCanonicalPath(), true);
			}
			if (delHome) {
				file.delete();
			}
		}
	}

}
