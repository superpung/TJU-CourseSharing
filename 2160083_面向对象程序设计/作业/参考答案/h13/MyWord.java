package com.huawei.classroom.student.h13;

public class MyWord implements Comparable<MyWord> {
	public String getWord() {
		return word;
	}

	public void setWord(String word) {
		this.word = word;
	}

	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = count;
	}

	private String word;

	 

	public MyWord(String word, int count) {
		super();
		this.word = word;
		this.count = count;
	}

	private int count = 0;

 

	@Override
	public int compareTo(MyWord o) {
		// TODO Auto-generated method stub
		if (this.count != o.count) {
			return -Integer.valueOf(this.count).compareTo(o.count);
		} else {
			return this.word.compareTo(o.word);
		}

	}
}
