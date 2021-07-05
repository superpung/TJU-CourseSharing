package com.huawei.classroom.student.h19.q05;

import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.io.Reader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.TreeSet;

public class StudentUtilA {

	/**
	 * 从一个文本文件中，一次读取一行，放到list中
	 * 
	 * @param fsrc
	 * @return
	 * @throws IOException
	 */
	private List<String> readLines(String fsrc) throws IOException {

		try (InputStream in = new FileInputStream(fsrc);
				Reader reader = new InputStreamReader(in, "UTF-8");
				// LineNumberReader 必须在其他流基础上构建
				LineNumberReader lineReader = new LineNumberReader(reader);) {
			String line = lineReader.readLine();
			List<String> lines = new ArrayList<String>();
			while (line != null) {
				lines.add(line);
				line = lineReader.readLine();
			}
			return lines;
		}
	}

	public StudentUtilA() {
	}

	private void setScores(List<String> lines, Map<String, MySudentA> map) {
		for (String line : lines) {

			line = line.replace(';', ',');
			String[] strs = line.split(",");
			String name = strs[0];
			String course = strs[1];
			String score = strs[2];
			MySudentA student = null;
			if (map.containsKey(name)) {
				student = map.get(name);
			} else {
				student = new MySudentA(name);
				map.put(name, student);
			}
			student.setScore(course, Integer.valueOf(score));
		}
	}

	private List<String> sortMap(Map<String, MySudentA> map) {
		TreeSet<MySudentA> set = new TreeSet<MySudentA>();
		Iterator<String> it = map.keySet().iterator();
		while (it.hasNext()) {
			String name = it.next();
			set.add(map.get(name));
		}
		List<String> names = new ArrayList<String>();
		Iterator<MySudentA> it2 = set.iterator();
		while (it2.hasNext()) {
			names.add(it2.next().getName());
		}
		return names;
	}

	public List<String> sort(String fileName) {
		try {
			List<String> lines = readLines(fileName);
			Map<String, MySudentA> map = new HashMap<String, MySudentA>();
			setScores(lines, map);
			return sortMap(map);

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}

	}

}
