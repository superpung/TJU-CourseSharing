package com.huawei.classroom.student.h12;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class Home12a {
	public Home12a() {
		// TODO Auto-generated constructor stub
	}
	/**
	 * 字符串content是一个超市的历次购物小票的合计，每次购物的明细之间用分号分割，每个商品之间用半角逗号分开
	 * 请找出   哪n个商品被同时购买的频率最高，将这n个商品名称的集合（set)返回 
	 * @param content，历次购物的明细，例如：炸鸡,可乐,啤酒;薯片,啤酒,炸鸡;啤酒,雪碧,炸鸡
	 * @param n
	 * @return 哪n个商品被同时购买的频率最高，将这n个商品名称的集合（set)返回 
	 * 不会出现并列的情况
	 */
	public Set<String> getFrequentItem(String content,int n)  {
		String[] lines = content.split(";");
		Map<Set<String>, Integer> map = new HashMap<Set<String>, Integer>();
		for (int i = 0; i < lines.length; i++) {
			String[] items = lines[i].split(",");
			
			//统计一次购物产生的组合数量
			System.out.println(lines[i]);
			count(items, map,n);
		}
		Iterator<Set<String>> it = map.keySet().iterator();
		Set<String> maxKey = null;
		//发现最大值
		int maxValue = 0;
		int maxCount=1; 
		while (it.hasNext()) {
			Set<String> key = it.next();			
			if (map.get(key) > maxValue) {
				maxValue = map.get(key);
				maxKey = key;
				maxCount=1;
			}else if(map.get(key) == maxValue) {
				maxCount++; 
			}
		}		
		if(maxCount> 1) {
			throw new IllegalArgumentException("max count="+maxCount );
		}
		return maxKey;
	}

	/**
	 * 取得一个组合
	 * @param items 本次购买的商品，每一个元素是一个商品
	 * @param map
	 * @param n 统计的商品组合（是1件组合、还是2件组合、还是3件组合)
	 */
	private void count(String[] items, Map<Set<String>, Integer> map,int n) {
		//存放所有的组合all
		Set<Set<String>> all=new HashSet<Set<String>>();
		//set完全是为了递归使用
		Set<String> set=new HashSet<String>();
		
		getAllCombination(items,0, n,all,set);
		//统一因为本次购物，产生的组合数量放到map中
		Iterator<Set<String>> it = all.iterator();
		while(it.hasNext()) {
			Set<String> key=it.next();
			int total=0;
			if(map.containsKey(key)) {
				total=map.get(key);
			}
			total++;
			map.put(key,total);
		}
	}
	
	/**
	 * 从strs字符串数组中，从start位置开始，取得数量为n个字符串的所有组合，将其放入到all中。其中每个组合放到一个Set<String>中
	 * 例如如果strs数组是a,b,c;start=0;n=2;则all=<<a,b>;<b,c>;<a,c>>(伪代码 在java里面不能直接这样写)
	 * @param strs 所有字符串
	 * @param start 从哪位开始统计
	 * @param n 字符串组合的数量
	 * @param all 存放历次组合出来的结果
	 * @param set 存放本次组合的结果
	 */
	private  void getAllCombination(String[] strs,int start,int n,Set<Set<String>> all,Set<String> set) {
		//如果set中已经满足数量=n了，那么本次递归可以结束了
		if(set.size()==n) {
			Set<String> temp=new HashSet<String>();
			temp.addAll(set);
			all.add(temp);
			Iterator<String> it=temp.iterator();			
			while(it.hasNext()) {
				System.out.print(it.next()+",");
			}
			System.out.print("\r\n");
			return;
		}
		//如果已经到末尾了，结束本次递归
		if(start>=strs.length) {
			return;
		}
		//选择start位的字符串，继续尝试
		set.add(strs[start]);		
		getAllCombination(strs,start+1,n,all,set);
		//把start位再移除掉
		set.remove(strs[start]);
		//第start的字符串先不选择，从下一位开始尝试
		getAllCombination(strs,start+1,n,all,set);

	}
}
