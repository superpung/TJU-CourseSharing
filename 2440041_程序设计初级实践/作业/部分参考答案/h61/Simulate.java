package com.huawei.classroom.student.h61;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

public class Simulate {
	private static int MAX_TRY = 100;
	private Param param;
	private List<Family> families;
	private List<Company> companies;
	private List<Person> persons;
	private Hospital hospital;
	private SimResult simResult;

	public Param getParam() {
		return param;
	}

	public Hospital getHospital() {
		return hospital;
	}

	public SimResult sim(Param param, int days) {
		this.param = param;
		families = new ArrayList<Family>();
		companies = new ArrayList<Company>();
		persons = new ArrayList<Person>();
		hospital = new Hospital(param.getHospitalSize());
		simResult = new SimResult();
		init();

		for (int i = 0; i < days; i++) {
			this.passOneDay();
			stat(i);
		}
		stat(days);
		return simResult;

	}

	private void init() {
		initFamilies();
		initPersons();
		initCompanies();
		initPatients();
	}

	private void initPersons() {
		for (int i = 0; i < param.getCityPopulation(); i++) {
			Person person = new Person(i);
			if(Util.getProbability(param.getImmuRate())) {
				person.setImmued(true);
			}
			this.persons.add(person);
			families.get(i / param.getFamilySize()).addPerson(person);
		}
	}

	private void initFamilies() {
		int familiesCount = param.getCityPopulation() / param.getFamilySize();
		for (int i = 0; i < familiesCount; i++) {
			families.add(new Family(i, param.getFamilySize(), param.getSpreadRateFamily()));

		}
	}

	private void initCompanies() {
		int companiesCount = param.getCityPopulation() / param.getCompanySize();
		for (int i = 0; i < companiesCount; i++) {
			companies.add(new Company(i, param.getCompanySize(), param.getSpreadRateCompany()));
		}
		List<Integer> indexes = new ArrayList<Integer>();
		for (int i = 0; i < persons.size(); i++) {
			indexes.add(i);
		}
		Collections.shuffle(indexes);
		for (int i = 0; i < indexes.size(); i++) {
			int pIndex = indexes.get(i);
			int cIndex = i / param.getCompanySize();

			companies.get(cIndex).addPerson(persons.get(pIndex));
		}

	}

	private void initPatients() {
		for (int i = 0; i < param.getInitPatients().size(); i++) {
			int index = param.getInitPatients().get(i);
			this.persons.get(index).infected();
		}
	}

	private void passOneDay() {
		for (Family family : families) {
			family.resetInfectionSource();
		}
		for (Company company : companies) {
			company.resetInfectionSource();
		}
		for (Person person : persons) {
			person.passOneDay(this);
		}
		this.hospital.clearBed();
	}

	private void stat(int day) {
		int deaths = 0;
		// 自愈+痊愈人数
		int cured = 0;
		// 目前仍然处于患病状态人数
		int patientsHospital = this.getHospital().getPatients().size();
		int patientsHome = this.getHospital().getWaitingPatients().size();
		int latents = 0;
		int healths = 0;
		int pHospital = 0;
		int pHome = 0;
		for (Person person : persons) {
			if (person.getState() == EnumState.cured) {
				cured++;
			} else if (person.getState() == EnumState.dead) {
				deaths++;
			} else if (person.getState() == EnumState.latent) {
				latents++;
			} else if (person.getState() == EnumState.ill_home) {
				pHome++;
			} else if (person.getState() == EnumState.ill_hospital) {
				pHospital++;
			} else if (person.getState() == EnumState.health) {
				healths++;
			} else {
				throw new java.lang.IllegalArgumentException("invalid state:" + person.getState());
			}
		}

		simResult.setCured(cured);
		simResult.setDeaths(deaths);
		simResult.setPatients(patientsHospital + patientsHome);
		simResult.setLatents(latents);
		if (day == 0) {
			 System.out.println("day \t healths \t deaths \t latents \t cured \t pHome \t pHospital");
		}

		System.out.println(
				day + "\t" + healths + "\t" + deaths + "\t" + latents + "\t" + cured + "\t" + pHome + "\t" + pHospital);
	}

}
