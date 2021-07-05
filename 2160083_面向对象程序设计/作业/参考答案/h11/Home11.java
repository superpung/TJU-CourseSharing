package com.huawei.classroom.student.h11;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class Home11 {

	public Home11() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * 字符串content是一个超市的历次购物小票的合计，每次购物的明细之间用分号分割，每个商品之间用半角逗号分开 请找出
	 * 哪两个商品被同时购买的频率最高，将这2个商品名称返回，名称之间用逗号分隔 测试的时候，商品名称可能增加新的商品，例如方便面、面包...
	 * 
	 * @param content，历次购物的明细，例如：炸鸡,可乐,啤酒;薯片,啤酒,炸鸡;啤酒,雪碧,炸鸡
	 * @return 哪两个商品被同时购买的频率最高，将这2个商品名称返回，名称之间用逗号分隔
	 */
	public String getFrequentItem(String content) {
		// 拆分每次购买过程
		String[] lines = content.split(";");
		Map<String, Integer> map = new HashMap<String, Integer>();
		for (int i = 0; i < lines.length; i++) {
			// 将每次购买的数量，拆分成单个商品
			String[] items = lines[i].split(",");
			// 统计商品购买的次数
			count(items, map);
		}
		Iterator<String> it = map.keySet().iterator();
		String maxKey = "";
		int maxValue = 0;
		// 找到最大的key
		while (it.hasNext()) {
			String key = it.next();
			if (map.get(key) > maxValue) {
				maxValue = map.get(key);
				maxKey = key;
			}
		}
		return maxKey;
	}

	/**
	 * 根据每次购买的商品，返回两两组合出现的次数，如果items 由 a b c构成，则map 里面返回的是a,b=1;b,c=1;a,c=1
	 * 
	 * @param items
	 *            单次购买的商品
	 * @param map
	 *            两两组合以后，在本次购买过程中出现次数;使用map中的key存放商品组合，value存放出现的次数
	 */
	private void count(String[] items, Map<String, Integer> map) {
		for (int i = 0; i < items.length; i++) {
			for (int j = i + 1; j < items.length; j++) {
				String itemA = items[i];
				String itemB = items[j];
				String key = itemA + "," + itemB;
				// 消除顺序性，不管是a,b还是b,a ,都让其成为a,b
				if (itemA.compareTo(itemB) > 0) {
					key = itemB + "," + itemA;
				}
				int value = 1;
				if (map.containsKey(key)) {
					value = 1 + map.get(key);
				}
				map.put(key, value);
			}
		}
	}

}
