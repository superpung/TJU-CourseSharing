package com.huawei.classroom.student.h17;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.Reader;
import java.util.HashMap;
import java.util.Map;

public class Param {

	public static final String HEALTH = "health";
	public static final String RANGE = "range";
	public static final String STRENGTH = "strength";

	private Map<String, Map<String, Integer>> allParamsMap = new HashMap<String, Map<String, Integer>>();

	public int getIntParam(EnumObjectType objectType, String paramName) {
		if (!allParamsMap.containsKey(objectType.toString())) {
			throw new IllegalArgumentException(objectType.toString());
		}
		Map<String, Integer> paramMap = allParamsMap.get(objectType.toString());
		if (!paramMap.containsKey(paramName)) {
			throw new IllegalArgumentException(paramName);
		}
		return paramMap.get(paramName);
	}

	public Param(String configName) throws FileNotFoundException, IOException {
		// TODO Auto-generated constructor stub
		try (Reader reader = new FileReader(configName);
				// LineNumberReader 必须在其他流基础上构建
				LineNumberReader lineReader = new LineNumberReader(reader);) {
			String line = lineReader.readLine();
			while (line != null) {
				if (line.startsWith("#") || line.trim().length() == 0) {

				} else {
					String[] strs = line.split("=");
					String left = strs[0];
					//String s="";
					int paramValue = Integer.valueOf(strs[1].trim());
					String[] names = left.split("\\.");
					String type = names[0];
					String paramName = names[1];

					Map<String, Integer> paramMap = null;
					if (allParamsMap.containsKey(type)) {
						paramMap = allParamsMap.get(type);
					} else {
						paramMap = new HashMap<String, Integer>();
					}
					paramMap.put(paramName, paramValue);
					allParamsMap.put(type, paramMap);
				}
				line = lineReader.readLine();

			}

		}

	}

}
