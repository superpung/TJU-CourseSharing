package com.huawei.classroom.student.h61;

/**
 * 不要修改这个类里面任何代码，原样交上来这个类即可。
 * @author Administrator
 *
 */
public class SimResult {
	//死亡人数
	private int deaths;
	//自愈+痊愈人数 
	private int cured;
	//目前仍然处于患病状态人数
	private int patients;
	public int getLatents() {
		return latents;
	}
	public void setLatents(int latents) {
		this.latents = latents;
	}
	//目前处于潜伏期状态人数
	private int latents;
	public int getDeaths() {
		return deaths;
	}
	public void setDeaths(int deaths) {
		this.deaths = deaths;
	}
	public int getCured() {
		return cured;
	}
	public void setCured(int cured) {
		this.cured = cured;
	}
	public int getPatients() {
		return patients;
	}
	public void setPatients(int patients) {
		this.patients = patients;
	}
	
}
