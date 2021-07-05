package com.huawei.classroom.student.h18;

import java.io.FileNotFoundException;
import java.io.IOException;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			//1 请你自己构造一个自己的类厂：MyClassFactory
			//2 该类能够用一个 .ini文件初始化, .ini文件的格式参考 my_config.ini，测试的时候这个文件名字可能改变，文件中包括中文，且文件一定为 UTF-8编码
			//.ini文件中描述了这个类厂能够动态创建的类和类的初始属性
			//初始化类厂
			MyClassFactory f=new MyClassFactory("D:\\course\\course\\exam\\src\\main\\java\\com\\huawei\\classroom\\student\\h18\\my_config.txt");
			//3 动态构造各种类，并且用.ini中的属性初始化，测试的时候 类名可能变化，例如  Orange.class ....
			//4 测试的时候，可能给其他对象，测试时候给的对象一定满足如下条件：
			//a 有空的构造函数，
			//b 中只包括了 Integer,String两种属性，并且有setXxx getXxx方法 
			Apple apple=f.createInstance(Apple.class);
			if("红色".equals(apple.getColor())&&500==apple.getWeight() ) {
				System.out.println("case 1 ok!");
			}
			Car car =f.createInstance(Car.class);
			if("大众".equals(car.getBrand())&&"黑色".equals(car.getColor())&&200000==car.getPrice()  ) {
				System.out.println("case 2 ok!");
			}
			
		} catch ( Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace(); 
		} 
		
		
	}

}
