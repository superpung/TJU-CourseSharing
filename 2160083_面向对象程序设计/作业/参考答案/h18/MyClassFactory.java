package com.huawei.classroom.student.h18;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Iterator;
import java.util.Map;


public class MyClassFactory {
	private Param param=null;
	public MyClassFactory(String configFile) throws FileNotFoundException, IOException {
		param=new Param(configFile);
	}
	public <T> T createInstance( Class<T> clazz) throws InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException, ClassNotFoundException{
		String className=clazz.getName();
		 
		T t = clazz.newInstance();
		Map<String,Object> props=param.getParamMap(className) ;
		Iterator<String> it=props.keySet().iterator();
		while(it.hasNext()) {
			String key=it.next();
			Object value=props.get(key); 
				String methName="set"+key.substring(0,1).toUpperCase()+key.substring(1,key.length());
				dynamicInvokeMethod(t,methName,value);
			 
		}
				 
		return t;
	}
	public Object dynamicInvokeMethod (Object obj, String methodName, Object... values)
			throws IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException,
			SecurityException, ClassNotFoundException {
		Class[] classes = new Class[values.length];
		for (int i = 0; i < values.length; i++) {
			classes[i] = values[i].getClass();
		}
		Method method = obj.getClass().getMethod(methodName, classes);
		return method.invoke(obj, values);
	}
}
