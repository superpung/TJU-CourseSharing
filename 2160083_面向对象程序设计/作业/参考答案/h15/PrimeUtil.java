/**
 * 
 */
package com.huawei.classroom.student.h15;

import java.util.ArrayList;
import java.util.List;

/**
 * 把你作业的代码写到这个类里面 不可以修改类的名字、包名、和固有的几个方法名以及方法的可见性 可以增加其他方法、属性、类 可以引用jdk的类
 * 不要引用jdk1.8以外第三方的包
 * 
 * @author cjy
 *
 */
public class PrimeUtil {

	/**
	 * 使用threadCount个线程计算出 start 和end 之间所有的质数，并按递增顺序放到list中 其中 end-start
	 * >threadCount
	 * 
	 * @param start
	 * @param end
	 * @param threadCount
	 * @return
	 * @throws Exception
	 */
	public List<Long> getPrimeList(long start, long end, int threadCount) throws Exception {
		List<Long> result = new ArrayList<Long>();
		List<List<Long>> lists = new ArrayList<List<Long>>();
		PrimeThread[] threads = new PrimeThread[threadCount];
		for (int i = 0; i < threadCount; i++) {
			long tstart = start + (end - start) / threadCount * i;
			long tend = start + (end - start) / threadCount * (i + 1);
			lists.add(new ArrayList<Long>());
			threads[i] = new PrimeThread(tstart, tend, lists.get(i));
			threads[i].start();
		}
		for (int i = 0; i < threadCount; i++) {
			threads[i].join();
			result.addAll(lists.get(i));
		}
		return result;
	}

}
