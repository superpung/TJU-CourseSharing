package com.huawei.classroom.student.h61;

public class Util {

	public static boolean getProbability(double probability) {
		return Math.random()<probability;
	}
	public static int getIntRand(int max) {
		return (int)(Math.random()*max);
	}
}
