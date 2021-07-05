package com.huawei.classroom.student.h61;

import java.util.Arrays;
import java.util.List;

/**
 * 不要修改这个类里面任何代码，原样交上来这个类即可。 
 * @author Administrator
 *
 */
public class Param {
	/**
	 * 1 一个城市由若干人口、家庭、公司
	 * 2 每天由白天+晚上 记为完整的一天。
	 * 3每个健康人白天在公司，晚上在家。
	 * 4潜伏期病人白天在公司，晚上在家。一旦度过潜伏期，如果医院有空余床位则去医院，否则全天在家排队等医院病床。
	 * 5医院有空床以后，按先到先得的顺序安排病人。
	 * 6每个病人每天在家以一定的概率痊愈，也以一定概率死亡。
	 * 7每个病人每天在医院以一定的概率痊愈，也以一定概率死亡。病人死亡和痊愈后，床位可以腾出来。
	 * 8痊愈的病人获得免疫能力。
	 * 9注射疫苗以后，可以降低感染可能性
	 * 10 注射疫苗的人是随机的
	 * 
	 * 
	 */
	//城市总人口数 1w-100W 城市人口数肯定能被  familySize、companySize 整除
	private int cityPopulation=100000;
	@Override
	public String toString() {
		return "Param [cityPopulation=" + cityPopulation + ", familySize=" + familySize + ", companySize=" + companySize
				+ ", spreadRateFamily=" + spreadRateFamily + ", spreadRateCompany=" + spreadRateCompany
				+ ", immuEffect=" + immuEffect + ", immuRate=" + immuRate + ", latentPeriod=" + latentPeriod
				+ ", healingRateHome=" + healingRateHome + ", deathRateHome=" + deathRateHome + ", healingRateHospital="
				+ healingRateHospital + ", deathRateHospital=" + deathRateHospital + ", hospitalSize=" + hospitalSize
				+ ", initPatients=" + initPatients + "]";
	}

	//每个家庭人口数 1-10 这个城市的 0-(familySize-1)号居民属于0号家庭，familySize - (familySize*2-1) 号居民属于1号家庭 ...
	private int familySize=4;
	//每个公司员工数 1-1000,每个居民 随机的隶属于一个公司，一旦固定下来以后，不存在跳槽的可能性
	private int companySize=100;
	//如果一个家庭存在病人（无论数量） 则任意一个健康人家庭成员  一晚上  被传染的概率
	private double spreadRateFamily=0.02;
	//如果一个公司存在病人（无论数量） 则任意个同公司健康人    一白天   被传染的概率
	private double spreadRateCompany=0.01;
	
	//疫苗的免疫率 在0-1之间 ，注射疫苗以后，对于注射了疫苗的人群：spreadRateFamily=spreadRateFamily*(1-immuEffect)；spreadRateCompany=spreadRateCompany*(1-immuEffect);
	private double immuEffect=0.8;
	//人群中有多少比例注射了疫苗，在0-1之间,注射疫苗的人必须是随机的，不能都固定在一个家庭
	private double immuRate=0.8;
	

	public double getImmuEffect() {
		return immuEffect;
	}

	public void setImmuEffect(double immuEffect) {
		this.immuEffect = immuEffect;
	}

	public double getImmuRate() {
		return immuRate;
	}

	public void setImmuRate(double immuRate) {
		this.immuRate = immuRate;
	}

	//潜伏期，潜伏期的病人具有传染性，只有超过潜伏期后，才不上班 去其医院排队治疗
	private int latentPeriod=7;
	//病人在家  每天自愈的概率
	private double healingRateHome=0.01;
	//病人在家 每天死亡的概率
	private double deathRateHome=0.01;	
	//病人在医院 每天治愈的概率
	private double healingRateHospital=0.1;
	//病人在医院 每天死亡的概率	
	private double deathRateHospital=0.001;
	//医院的床位数
	private int hospitalSize=1000;
	
	//城市中初始的病人编号，这些病人都处于生病的第0天，需要在第latentPeriod天 才能发现患病。
	private List<Integer> initPatients= Arrays.asList(0,100,800,900);
	
	
	public int getCityPopulation() {
		return cityPopulation;
	}

	public void setCityPopulation(int cityPopulation) {
		this.cityPopulation = cityPopulation;
	}

	public int getFamilySize() {
		return familySize;
	}

	public void setFamilySize(int familySize) {
		this.familySize = familySize;
	}

	public int getCompanySize() {
		return companySize;
	}

	public void setCompanySize(int companySize) {
		this.companySize = companySize;
	}

	public double getSpreadRateFamily() {
		return spreadRateFamily;
	}

	public void setSpreadRateFamily(double spreadRateFamily) {
		this.spreadRateFamily = spreadRateFamily;
	}

	public double getSpreadRateCompany() {
		return spreadRateCompany;
	}

	public void setSpreadRateCompany(double spreadRateCompany) {
		this.spreadRateCompany = spreadRateCompany;
	}

	public int getLatentPeriod() {
		return latentPeriod;
	}

	public void setLatentPeriod(int latentPeriod) {
		this.latentPeriod = latentPeriod;
	}

	public double getHealingRateHome() {
		return healingRateHome;
	}

	public void setHealingRateHome(double healingRateHome) {
		this.healingRateHome = healingRateHome;
	}

	public double getDeathRateHome() {
		return deathRateHome;
	}

	public void setDeathRateHome(double deathRateHome) {
		this.deathRateHome = deathRateHome;
	}

	public double getHealingRateHospital() {
		return healingRateHospital;
	}

	public void setHealingRateHospital(double healingRateHospital) {
		this.healingRateHospital = healingRateHospital;
	}

	public double getDeathRateHospital() {
		return deathRateHospital;
	}

	public void setDeathRateHospital(double deathRateHospital) {
		this.deathRateHospital = deathRateHospital;
	}

	public int getHospitalSize() {
		return hospitalSize;
	}

	public void setHospitalSize(int hospitalSize) {
		this.hospitalSize = hospitalSize;
	}

	public List<Integer> getInitPatients() {
		return initPatients;
	}

	public void setInitPatients(List<Integer> initPatients) {
		this.initPatients = initPatients;
	}


	
			
}
