package com.huawei.classroom.student.h61;

public class Test {

	public Test() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Simulate simulate=new Simulate();
		Param param=new Param();
		//测试的时候 days介于1-1000之间
		int days=100;
		//模拟某种疾病在一个城市的传播情况。所有参数见 Param。模拟结果放入SimResult中
		//不要修改Param,SimResult的代码
		//现在是第0天的白天的开始，模拟days天以后，城市居民的健康状况
		//完成SimResult 类，可以适当的增加其他的类。
		//要求算法适当的考虑算法效率问题
		long l=System.currentTimeMillis();
		//param.setImmuRate(0);
		SimResult result=simulate.sim(param,days);
		System.out.println("参数取值如下："+param);
		System.out.println((System.currentTimeMillis()-l)+" cost ");
		System.out.println(days+" 天后 情况如下");
		System.out.println("死亡人数："+result.getDeaths());
		System.out.println("自愈+治愈人数:"+result.getCured());
		System.out.println("现有病人数量:"+result.getPatients());
		System.out.println("现有潜伏期人数:"+result.getLatents());
		System.out.println("健康人数:"+(param.getCityPopulation()-result.getCured()- result.getDeaths()-result.getPatients()-result.getLatents()));
	}
}
