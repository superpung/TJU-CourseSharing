package com.huawei.classroom.student.h61;

import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class Hospital {
	private int size;
	private Set<Person> patients=new HashSet<Person>();
    private List<Person> waitingPatients=new LinkedList<Person>(); 
    
    public Set<Person> getPatients() {
		return patients;
	}
	public List<Person> getWaitingPatients() {
		return waitingPatients;
	}
	public Hospital(int size) {
		super();
		this.size = size;
	}
	public void appendPatients(Person person) {
    	if(patients.size()<size) {
    		patients.add(person);
    		person.setState(EnumState.ill_hospital);
    	}else {
    		waitingPatients.add(person);
    	}
    }
    public void clearBed() {
    	Iterator<Person> it = patients.iterator();
    	while(it.hasNext()) {
    		Person person=it.next();
    		if(person.getState()!=EnumState.ill_hospital) {
    			it.remove();
    		}    		
    	}
    	it = waitingPatients.iterator();
    	while(it.hasNext()) {
    		Person person=it.next();
    		if(person.getState()!=EnumState.ill_home) {
    			it.remove();
    		}
    		
    	}
    	while(waitingPatients.size()>0&&patients.size()<size) {
    		Person person=waitingPatients.get(0);
    		patients.add(person);
    		person.setState(EnumState.ill_hospital);
    		waitingPatients.remove(0);
    	}
    	 
    }
    
}
