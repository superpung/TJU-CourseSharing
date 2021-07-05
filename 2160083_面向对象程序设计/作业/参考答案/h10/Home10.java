package com.huawei.classroom.student.h10;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

/**
 * 把你作业的代码写到这个类里面
 * 不可以修改类的名字、包名、和固有的几个方法名以及方法的可见性
 * 可以增加其他方法、属性、类
 * 可以引用jdk的类
 * 不要引用jdk1.8以外第三方的包
 * 
 * @author cjy
 *
 */
public class Home10 {
	public Home10() {
	} 
	/**
	 * 将一个字符串中字符按出现频率的高到低排序返回，如果两个字符出现的频率一样，则将最先出现的字符排在前面
	 * 例如：orderChar(“abcdefg”)返回 “abcdefg” 
	 * orderChar(“abcdefgg”)返回 “gabcdef”
	 * orderChar(“abcdefgge”)返回 “egabcdf”
	 * orderChar(“天津大学软件学院”)返回 “学天津大软件院”
	 * @param content
	 * @return
	 */
	public String orderChar(String content) {
		char[] chars = content.toCharArray();
		Map<Character, MyChar> map = new HashMap<Character, MyChar>();
//		map.containsKey('a');
//		map.get('a').compareTo("");
		for (int i = 0; i < chars.length; i++) {
			char ch = chars[i];
			MyChar myChar = null;
			if (map.containsKey(ch)) {
				myChar = map.get(ch);
			} else {
				myChar = new MyChar(ch, i);
			}
			myChar.incCount();
			map.put(ch, myChar);
		}
		Set<MyChar> set = new TreeSet<MyChar>();
		set.addAll(map.values());
		Iterator<MyChar> it = set.iterator();
		StringBuffer buf = new StringBuffer();
		while (it.hasNext()) {
			buf.append(it.next().getCh());
		}
		return buf.toString();
	}
	
}
