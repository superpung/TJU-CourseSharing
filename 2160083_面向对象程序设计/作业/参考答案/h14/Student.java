package com.huawei.classroom.student.h14;

public class Student {
	private String classId;
	private String id; 
	public String getClassId() {
		return classId;
	}
	public void setClassId(String classId) {
		this.classId = classId;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	private String name;
	public Student( String id, String name,String classId) {
		super();
		this.classId = classId;
		this.id = id;
		this.name = name;
	}
	@Override
	public String toString() {
		return "Student [classId=" + classId + ", id=" + id + ", name=" + name + "]";
	}
	 
	
}
