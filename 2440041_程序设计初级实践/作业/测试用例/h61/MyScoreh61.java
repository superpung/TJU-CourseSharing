/**
 * 
 */
package com.huawei.classroom.student.h61;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
import com.huawei.classroom.test_case.Cat;
import com.huawei.classroom.test_case.Employee;

/**
 * @author Administrator
 *
 */
public class MyScoreh61 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh61(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {

		int days = 100;

		Simulate simulate = new Simulate();
		String method = "test case 1 DeathRate=0";
		CTestCase t = new CTestCase(vo);
		t.setScore(20);
		t.setMethod(method);
		t.setNum("1");
		Param param = createParam();
		param.setDeathRateHome(0);
		param.setDeathRateHospital(0);
		SimResult result = simulate.sim(param, days);
		t.getResult().apendDetail("getDeaths="+result.getDeaths());
		t.setPredicate((SimResult h) -> {
			return h.getDeaths() == 0;
		});
		t.test(result);

		simulate = new Simulate();
		method = "test case 2 SpreadRate=0";
		t.setMethod(method);
		t.setNum("2");
		param = createParam();
		param.setSpreadRateCompany(0);
		param.setSpreadRateFamily(0);
		result = simulate.sim(param, days);
		t.getResult().apendDetail("\r\n");
		t.getResult().apendDetail("getPatients="+result.getPatients());
		t.getResult().apendDetail("getDeaths="+result.getDeaths());
		t.getResult().apendDetail("getCured="+result.getCured());
		t.setPredicate((SimResult h) -> {
			return h.getPatients() + h.getDeaths() + h.getCured() == 4;
		});
		t.test(result);
		

		simulate = new Simulate();
		method = "test case 3 ImmuEffect=1 setImmuRate=1";
		t.setMethod(method);
		t.setNum("3");
		param = createParam();
		param.setImmuEffect(1);
		param.setImmuRate(1);
		result = simulate.sim(param, days);
		t.getResult().apendDetail("\r\n");
		t.getResult().apendDetail("getPatients="+result.getPatients());
		t.getResult().apendDetail("getDeaths="+result.getDeaths());
		t.getResult().apendDetail("getCured="+result.getCured());
		t.setPredicate((SimResult h) -> {
			return h.getPatients() + h.getDeaths() + h.getCured() == 4;
		});
		t.test(result);


		simulate = new Simulate();
		method = "test case 4  ImmuEffect=0 ";
		t.setMethod(method);
		t.setNum("4");
		param =createParam(); 
		param.setImmuEffect(0);
		result = simulate.sim(param, days);

		t.getResult().apendDetail("\r\n");
		t.getResult().apendDetail("getDeaths="+result.getDeaths());
		t.getResult().apendDetail("getPatients="+result.getPatients());
		t.getResult().apendDetail("getCured="+result.getCured());
		t.getResult().apendDetail("getLatents="+result.getLatents());	
		t.setPredicate((SimResult h) -> {
			return rangeEq(100000-26590, h.getPatients() + h.getDeaths() + h.getCured());
		});
		t.test(result);
		
		simulate = new Simulate();
		method = "test case 5  default setting";
		t.setMethod(method);
		t.setNum("5");
		param =createParam(); 
		param.setImmuEffect(0.8);
		param.setImmuRate(0.8);
		result = simulate.sim(param, days);

		t.getResult().apendDetail("\r\n");
		t.getResult().apendDetail("getDeaths="+result.getDeaths());
		t.getResult().apendDetail("getPatients="+result.getPatients());
		t.getResult().apendDetail("getCured="+result.getCured());
		t.getResult().apendDetail("getLatents="+result.getLatents());	
		t.setPredicate((SimResult h) -> {
			return rangeEq(98571, 100000-(h.getPatients() + h.getDeaths() + h.getCured()));
		});
		t.test(result);

	}

	public boolean rangeEq(int a, int b) {
		double range = 0.5;
		return (a * (1 - range)-500) < b && b < (a * (1 + range)+500);
	}

	public Param createParam() {
		Param param = new Param();
		param.setCityPopulation(100000);
		param.setFamilySize(4);
		param.setCompanySize(100);
		param.setSpreadRateFamily(0.02);
		param.setSpreadRateCompany(0.01);
		param.setLatentPeriod(7);
		param.setHealingRateHome(0.01);
		param.setDeathRateHome(0.01);
		param.setHealingRateHospital(0.1);
		param.setDeathRateHospital(0.001);
		param.setHospitalSize(100);
		param.setInitPatients(Arrays.asList(0, 100, 800, 900));

		return param;
	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh61("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
