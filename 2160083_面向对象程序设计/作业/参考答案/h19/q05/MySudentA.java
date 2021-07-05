package com.huawei.classroom.student.h19.q05;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class MySudentA implements Comparable {
	public static String[] subjects = { "语文", "数学", "英语" };
	private String name;
	private int totalScore = 0;
	private Map<String, Integer> scores = new HashMap<String, Integer>();

	public MySudentA(String name) {
		this.name = name;
	}

	public String getName() {
		return name;
	}

	public void setScore(String sub, int score) {
		scores.put(sub, score);
		reCalcScore();
	}

	public void reCalcScore() {
		for (int i = 0; i < subjects.length; i++) {
			if (!scores.containsKey(subjects[i])) {
				scores.put(subjects[i], 0);
			}
		}
		totalScore = 0;
		Iterator<String> it = scores.keySet().iterator();
		while (it.hasNext()) {
			totalScore = totalScore + scores.get(it.next());
		}

	}

	public int getScore(String sub) {
		return scores.get(sub);
	}

	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub

		MySudentA that = (MySudentA) o;
		if (this.totalScore != that.totalScore) {
			return -Integer.valueOf(this.totalScore).compareTo(that.totalScore);
		} else {
			for (int i = 0; i < subjects.length; i++) {
				String sub = subjects[i];
				if (this.getScore(sub) != that.getScore(sub)) {
					return -Integer.valueOf(this.getScore(sub)).compareTo(that.getScore(sub));
				}
			}
			return this.name.compareTo(that.name);
		}

	}

}
