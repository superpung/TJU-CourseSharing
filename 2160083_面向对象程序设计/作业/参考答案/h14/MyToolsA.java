package com.huawei.classroom.student.h14;

import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.LineNumberReader;
import java.io.OutputStream;
import java.io.Reader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
/**
 * 在本包下增加合适的类和方法， 本程序不但要测试通过，还需要写适当的注释
 * 
 * 不要引用jdk1.8以外第三方的包
 * 
 * @author cjy
 *
 */
public class MyToolsA {

	/**
	 * 
	 * @param studentListFile  存放学生名单的文件名
	 * @param picDir 图片存放的目录（不会包含子目录）
	 */
	public MyToolsA( ) {
		// TODO Auto-generated constructor stub
	}

	
	public Set<String> copyToTargetDirAndReturnNoExist(String studentListFile,String srcDir,String target) throws Exception {
		List<Student> stuList=this.readStudents(studentListFile);
		Set<String> noexist=new HashSet<String>();
		for(Student stu:stuList) {
			String srcFile=srcDir+stu.getId()+".jpg";
			File src=new File(srcFile);
			if(src.exists()) {
				String classDir=target+"/"+stu.getClassId()+"/";
				File dirTarget=new File(classDir);
				if(!dirTarget.exists()) {
					dirTarget.mkdirs();
				}
				String targtFilename=classDir+stu.getId()+ "_"+stu.getName()+".jpg";
				this.copyFile(srcFile, targtFilename);
			}else {
				noexist.add(stu.getId());
			}
			
		}
		return noexist;
		
	}
	
	public Set<String> getNoPicStudentList()  throws Exception {
		return null;
	}

	 
	private List<Student> readStudents(String fsrc) throws IOException{
		List<String>  lines=readLines(  fsrc) ;
		List<Student> students=new ArrayList<Student>();
		for(String line:lines) {
			String[] strs=line.split("\t");
			Student student=new Student(strs[0],strs[1],strs[2]);
			students.add(student);
			//System.out.println(student );
		}
		return students;
	}
	private  List<String> readLines(String fsrc) throws IOException {
		try (Reader reader = new FileReader(fsrc); 
				//LineNumberReader 必须在其他流基础上构建
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
	/**
	 * 复制IO流
	 * 
	 * @param in
	 * @param out
	 * @throws IOException
	 */
	private   void copyIO(InputStream in, OutputStream out) 
			throws IOException {
		byte[] buf = new byte[1024*8];
		
		/**
		 * 从输入流读取内容并写入到另外一个流的典型方法
		 */
		int len = in.read(buf);
		while (len != -1) {
			out.write(buf, 0, len);
			len = in.read(buf);
		}
	}

	/**
	 * 复制文件
	 * 
	 * @param fsrc
	 * @param fdest
	 * @throws IOException
	 */
	private void copyFile(String fsrc, String fdest) throws IOException {
		InputStream in = null;
		OutputStream out = null;
		try {
			in = new FileInputStream(fsrc);
			out = new FileOutputStream(fdest, true);
			copyIO(in, out);
		} finally {
			close(in);
			close(out);
		}
	}

	/**
	 * 关闭一个输入 输出流
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
}
