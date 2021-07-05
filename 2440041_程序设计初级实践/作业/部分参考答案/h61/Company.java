package com.huawei.classroom.student.h61;

public class Company extends GroupedSite {

	public Company(int id, int size, double spreadRate) {
		super(id, size, spreadRate);
	}
	@Override
	public void addPerson(Person person) {
		super.addPerson(person);
		person.setCompany(this);
	}
	@Override
	public boolean checkInfection(Person person) {
		// TODO Auto-generated method stub
		
		return  person.getState()==EnumState.latent;
	}
}
