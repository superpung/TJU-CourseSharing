
package com.huawei.classroom.student.h13;

import java.io.Closeable;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.TreeSet;

/**
 * 在本包下增加合适的类和方法，使得Test类能够测试通过 具体要求见实验一 注意 本程序不但要测试通过，还需要写适当的注释
 * 
 * 不要引用jdk1.8以外第三方的包
 * 
 * @author cjy
 *
 */
public class AnalysisA {
	private String[] chapters = null;
	private String content = null;

	/**
	 * @throws Exception
	 * 
	 */
	public AnalysisA(String filename) throws Exception {
		// TODO Auto-generated constructor stub
		content = readFromTxt(filename);
		chapters = splitContentToChapter(content);
		content = content.replaceAll(" ", "");
		content = content.replaceAll(",", "");
		content = content.replaceAll("：", "");
		content = content.replaceAll("“", "");
		content = content.replaceAll("”", "");
		content = content.replaceAll("。", "");
		content = content.replaceAll("．", "");
		content = content.replaceAll("，", "");
		content = content.replaceAll("？", "");
		content = content.replaceAll("\"", "");
		content = content.replaceAll("\r\n", "");

	}

	/**
	 * 提示 ：将一个文本文件读取到一个字符串中返回
	 * 
	 * @param filename
	 *            红楼梦文本文件的全路径名
	 * @return 文本的内容
	 */
	private String readFromTxt(String filename) throws Exception {
		Reader reader = null;
		try {
			StringBuffer buf = new StringBuffer();
			char[] chars = new char[1024];
			// InputStream in=new FileInputStream(filename);

			reader = new InputStreamReader(new FileInputStream(filename), "UTF-8");
			int readed = reader.read(chars);
			while (readed != -1) {
				buf.append(chars, 0, readed);
				readed = reader.read(chars);
			}
			return buf.toString();
		} finally {
			close(reader);
		}
	}
	public List<String> getTopNWords(int n,int wordLen) {		
		Map<String, Integer> map = new HashMap<String, Integer>();
		for (int i = 0; i < content.length() - (wordLen-1); i++) {
			String word = content.substring(i, i + wordLen);
			int count = 0;
			if (map.containsKey(word)) {
				count = (Integer) map.get(word);
			}
			map.put(word, count + 1);
		}
		Iterator<String> it = map.keySet().iterator();
		TreeSet<MyWord> set = new TreeSet<MyWord>();

		while (it.hasNext()) {
			String key = (String) it.next();
			
			int count = map.get(key);
			set.add(new MyWord(key, count));
		}
		Iterator<MyWord> itw = set.iterator();
		List<String> top = new ArrayList<String>();
		while (top.size() < n) {
			MyWord word = itw.next();
			System.out.println(word.getWord() + "=" + word.getCount());
			top.add(word.getWord());
		}
		return top;

	}


	public List<String> getTopNWords(int n) { 
		return getTopNWords(n,2);

	}

	/**
	 * 关闭输入输入流
	 * 
	 * @param inout
	 */
	private void close(Closeable inout) {
		if (inout != null) {
			try {
				inout.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	/**
	 * 将红楼梦文本文件拆分为120个章节
	 * 
	 * @param content
	 * @return 返回120个元素的字符串数组
	 */
	private String[] splitContentToChapter(String content) {
		// 提示 使用 content.split(" 第[一,二,三,四,五,六,七,八,九,十,零]{1,5}回 ");正则表达拆分
		// 百度一下正则表达式
		String contents[] = content.split(" 第[一,二,三,四,五,六,七,八,九,十,零]{1,5}回 ");

		return contents;
	}

	/**
	 * 统计某个字符 在一个字符串里面出现的频度 方法1
	 * 
	 * @param content
	 * @param sub
	 * @return
	 */
	private int getCount(String content, String sub) {
		int count = 0;
		if (content.contains(sub)) {
			while (true) {
				int indexof = content.indexOf(sub);
				if (indexof != -1) {
					content = content.substring(indexof + sub.length());
					count++;
				} else
					break;
			}
		}
		return count;
	}
	//方法2
	private int getCount2(String content, String sub) {
		int count = 0;
		int indexof = content.indexOf(sub);
		while (indexof >= 0) {
			count++;
			indexof = content.indexOf(sub, indexof + sub.length());
		}
		return count;

	}

	/**
	 * 计算红楼梦中某个字符串 str 出现的频率
	 * 
	 * @param filename
	 *            存放了红楼梦这本书的文本文件名
	 * @param str
	 *            要统计的字符串
	 * @return 一个长度是120的一维数组
	 */
	public int[] getStringFrequent(String str) throws Exception {

		// 提示 3 针对每章 调用 getCount方法
		int[] Frequent = new int[chapters.length - 1];
		for (int i = 1; i < chapters.length; i++) {
			Frequent[i - 1] = getCount2(chapters[i], str);
		}
		return Frequent;
	}

}
