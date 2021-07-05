package com.huawei.classroom.student.h10;

/**
 * 参考答案
 * @author Administrator
 *
 */
public class MyChar implements Comparable {
	private char ch;
	private int pos;
	private int count;

	public MyChar(char ch,int pos) {
		// TODO Auto-generated constructor stub
		this.ch=ch;
		this.pos = pos;
		this.count = 0;
	}

	public char getCh() {
		return ch;
	}

	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		if (o instanceof MyChar) {
			MyChar that = (MyChar) o;
			if (this.count != that.count) {				
				return -Integer.valueOf(this.count).compareTo(that.count);
			} else {
				return Integer.valueOf(this.pos).compareTo(that.pos);
			}
		} else {
			throw new java.lang.IllegalArgumentException();
		}
	}

	public void incCount() {
		count++;
	}

}
