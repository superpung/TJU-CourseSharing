package com.huawei.classroom.student.h61;

public class Family extends GroupedSite {
	public Family(int id, int size, double spreadRate) {
		super(id, size, spreadRate);
	}
	@Override
	public void addPerson(Person person) {
		super.addPerson(person);
		person.setFamily(this);
	}
	@Override
	public boolean checkInfection(Person person) {
		// TODO Auto-generated method stub
		
		return person.getState()==EnumState.ill_home||person.getState()==EnumState.latent;
	}
}
