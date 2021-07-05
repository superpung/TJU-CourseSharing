/**
 * 
 */
package com.huawei.classroom.student.h06;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;
/**
 * @author Administrator
 *
 */
public class MyScoreh06 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh06(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {
		
		// TODO Auto-generated method stub
		CTestCase t=new CTestCase(vo);
		
		
		GameBase gameBase=GameBase.createGameBase(10,10);
		Barrack barrack=(Barrack)gameBase.building(EnumObjectType.barrack, 50, 50);
		WarFactory warFactory=(WarFactory)gameBase.building(EnumObjectType.warFactory, 100, 100);
		Tank mediumTank1=(MediumTank)warFactory.building(EnumObjectType.mediumTank);
		Tank heavyTank1=(HeavyTank)warFactory.building(EnumObjectType.heavyTank );
		
		RPGSoldier rPGSoldier1=(RPGSoldier)barrack.traing(EnumObjectType.RPGSoldier );
		Dog dog1=(Dog)barrack.traing(EnumObjectType.dog );
		RifleSoldier  rifleSoldier1=(RifleSoldier)barrack.traing(EnumObjectType.rifleSoldier );

		t.setScore(20);
		String method="mediumTank1.attack(rPGSoldier1)";
		mediumTank1.attack(rifleSoldier1);		
		t.setMethod(method);
		t.setPredicate((RifleSoldier h)->h.getHealth()==50);
		t.test(rifleSoldier1);
		
		method="rifleSoldier1.attack(mediumTank1)";
		rifleSoldier1.attack(mediumTank1);		
		t.setMethod(method);
		t.setPredicate((MediumTank  h)->h.getHealth()==100);
		t.test(mediumTank1);
		
		rifleSoldier1.move(40, 40);
		rifleSoldier1.move(2, 4);
		method="mediumTank1.attack(rifleSoldier1)";
		mediumTank1.attack(rifleSoldier1);		
		t.setMethod(method);
		t.setPredicate((RifleSoldier  h)->h.getHealth()==40);
		t.test(rifleSoldier1);
		
		method="rifleSoldier1.attack(mediumTank1)";
		rifleSoldier1.attack(mediumTank1);		
		t.setMethod(method);
		t.setPredicate((MediumTank  h)->h.getHealth()==100);
		t.test(mediumTank1);
		
		t.setScore(10);
		dog1.attack(rPGSoldier1);
		dog1.attack(rPGSoldier1);	 
		method="Soldier.getLivingSoldierCount()";
		t.setMethod(method);		 		 
		t.setPredicate((RifleSoldier  h)->Soldier.getLivingSoldierCount()==1);
		t.test(rifleSoldier1);


		method="Soldier.getDeadedSoldierCount()";
		t.setMethod(method);		 		 
		t.setPredicate((RifleSoldier  h)->Soldier.getDeadedSoldierCount()==1);
		t.test(rifleSoldier1);
		
 
	}
	public static void main(String[] args) {
		QuestionTempVo vo=new QuestionTempVo();
		try {
			new MyScoreh06("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
