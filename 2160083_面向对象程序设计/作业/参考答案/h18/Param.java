package com.huawei.classroom.student.h18;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.util.HashMap;
import java.util.Map;

public class Param {

	private Map<String, Map<String, Object>> allParamsMap = new HashMap<String, Map<String, Object>>();

	public Map<String, Object> getParamMap(String className) {

		return allParamsMap.get(className);
	}

	public Param(String configName) throws FileNotFoundException, IOException {
		// TODO Auto-generated constructor stub

		try (InputStream in = new FileInputStream(configName);
				InputStreamReader inReader = new InputStreamReader(in, "UTF-8");
				// LineNumberReader 必须在其他流基础上构建
				LineNumberReader lineReader = new LineNumberReader(inReader);) {
			String line = lineReader.readLine();
			while (line != null) {
				if (line.startsWith("#") || line.trim().length() == 0) {

				} else {
					String[] strs = line.split("=");
					String left = strs[0];
					String right = strs[1];

					// String s="";
					int dotPos = left.lastIndexOf(".");
					String className = left.substring(0, dotPos);
					String paramName = left.substring(dotPos + 1, left.length());

					Map<String, Object> paramMap = null;
					if (allParamsMap.containsKey(className)) {
						paramMap = allParamsMap.get(className);
					} else {
						paramMap = new HashMap<String, Object>();
					}
					if (right.startsWith("\"")) {
						paramMap.put(paramName, right.substring(1, right.length() - 1));
					} else {
						paramMap.put(paramName, Integer.valueOf(right));
					}
					allParamsMap.put(className, paramMap);
				}
				line = lineReader.readLine();

			}

		}

	}

}
