package com.huawei.classroom.student.h61;

import java.util.ArrayList;
import java.util.List;

public abstract class GroupedSite {
	private int id;
	private int size;
	private double spreadRate;
	private List<Person> persons;
	private boolean containsInfectionSource=false;
	public int getId() {
		return id;
	}

 

	public GroupedSite(int id, int size, double spreadRate) {
		super();
		this.id = id;
		this.size = size;
		this.spreadRate = spreadRate;
		persons=new ArrayList<Person>();
	}



	public GroupedSite(int id, int size) {
		super();
		this.id = id;
		this.size = size;
		this.persons=new ArrayList<Person>();
	}

	public int getSize() {
		return size;
	}

	public void setSize(int size) {
		this.size = size;
	}
	
	public boolean isContainsInfectionSource() {
		return containsInfectionSource;
	}
	
	
	 
	public void addPerson(Person person) {
		this.persons.add(person);
	}
	public boolean isFull() {
		return this.persons.size()>=this.size;
	}
	public void resetInfectionSource() {
		this.containsInfectionSource=false;
		for(Person person:persons) {
			if(checkInfection(person) ) {
				this.containsInfectionSource=true;
				break;
			}
		}
		
	}
	public abstract boolean checkInfection(Person person) ;
}
