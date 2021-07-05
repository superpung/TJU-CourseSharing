package com.huawei.classroom.student.h15;

import java.util.List;

public class PrimeThread extends Thread {
	private long start;
	private long end;
	private List<Long> list;
	public PrimeThread(long start, long end,List<Long> list) {
		super();
		this.start = start;
		this.end = end;
		this.list=list;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(long j=start;j<end;j++) {
			if(isPrime(j)) {
				list.add(j);
			}
		}
	}	
	private boolean isPrime(long i) {
		long endLoop=(long)(Math.sqrt(i)+1);
		for(long j=2;j<endLoop;j++) {		
			if(i%j==0) {
				return false;
			}
		}
		return true;		
	}
}
