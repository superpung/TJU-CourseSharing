package com.huawei.classroom.student.h15;

public class ThreadUtil extends Thread{
	private StringBuffer buf=new StringBuffer();

	public ThreadUtil(StringBuffer buf) {
		super();
		this.buf = buf; 
	}
	 @Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			Thread.sleep(500);
			buf.append("ok");
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
