package com.huawei.classroom.student.h61;

public class Person {
	private int id;
	private Family family;
	private Company company;
	private EnumState state;
	private int latentDays = -1;
	private boolean immued=false;

	public boolean isImmued() {
		return immued;
	}

	public void setImmued(boolean immued) {
		this.immued = immued;
	}

	public Person(int id) {
		this.id=id;
		state=EnumState.health;
		latentDays = -1;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public Family getFamily() {
		return family;
	}

	public void setFamily(Family family) {
		this.family = family;
	}

	public Company getCompany() {
		return company;
	}

	public void setCompany(Company company) {
		this.company = company;
	}

	public EnumState getState() {
		return state;
	}

	public void setState(EnumState state) {
		this.state = state;
	}

	public int getLatentDays() {
		return latentDays;
	}

	public void setLatentDays(int latentDays) {
		this.latentDays = latentDays;
	}

	public void infected() {
		this.state = EnumState.latent;
		this.latentDays = 0;
	}

	public void passOneDay(Simulate simulate) {
		if (this.getState() == EnumState.ill_home) {
			if (Util.getProbability(simulate.getParam().getDeathRateHome())) {
				this.state = EnumState.dead;
			}
			if (Util.getProbability(simulate.getParam().getHealingRateHome())) {
				this.state = EnumState.cured;
			}
		}
		if (this.getState() == EnumState.ill_hospital) {
			if (Util.getProbability(simulate.getParam().getDeathRateHospital())) {
				this.state = EnumState.dead;
			}
			if (Util.getProbability(simulate.getParam().getHealingRateHospital())) {
				this.state = EnumState.cured; 
			}
		}
		if (this.state == EnumState.latent) {
			latentDays++;
		}

		if (this.state == EnumState.health) {
			double effect=0;
			if(this.isImmued()) {
				effect=simulate.getParam().getImmuEffect();
			}
			if (this.family.isContainsInfectionSource()) {
				checkInfected(simulate.getParam().getSpreadRateFamily()*(1-effect) );
			}
			if (this.company.isContainsInfectionSource()) {
				checkInfected(simulate.getParam().getSpreadRateCompany()*(1-effect));
			}
			
		}

		if (this.state == EnumState.latent) {
			if (this.latentDays > simulate.getParam().getLatentPeriod()) {
				this.state = EnumState.ill_home;
				simulate.getHospital().appendPatients(this);
			}
			
		}

	}

	public void checkInfected(double spreadRate) {
		if (this.getState() == EnumState.health) {
			if (Util.getProbability(spreadRate)) {
				this.infected();
			}
		}
	}

	@Override
	public int hashCode() {
		// TODO Auto-generated method stub
		return this.id;
	}

	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		if (obj instanceof Person) {
			return this.id == ((Person) obj).id;
		} else {
			return false;
		}
	}

}
