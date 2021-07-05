package ch12;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * 这个例子演示日期的几种用法
 * @author cjy
 *
 */
public class DateDemo {

	public DateDemo() {
	}

	public static void main(String[] args) {
		try {
			System.out.println(new java.util.Date());
			 
			//日期转换为字符串
			String str = dateToStr(new java.util.Date(), "yyyy-MM-dd HH:mm:ss");
			System.out.println(str);
			
			//字符串转换为日期
			Date date = strToDate(str, "yyyy-MM-dd HH:mm:ss");
			System.out.println(date);
			//毫秒转换为日期
			long curMills=System.currentTimeMillis();
			Date date2=new Date(curMills);
			System.out.println(date2);
			
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	public static String dateToStr(java.util.Date date, String pattern) {
		SimpleDateFormat df = new SimpleDateFormat(pattern);
		return df.format(date);
	}

	public static Date strToDate(String date, String pattern) throws ParseException {
		SimpleDateFormat formatter = new SimpleDateFormat(pattern);
		java.util.Date outDate = formatter.parse(date);
		return outDate;
	}

}
