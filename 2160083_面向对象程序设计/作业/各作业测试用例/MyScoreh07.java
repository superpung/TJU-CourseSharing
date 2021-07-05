/**
 * 
 */
package com.huawei.classroom.student.h07;

import com.huawei.classroom.teacher.myexam.AbstractMyScore;
import com.huawei.classroom.teacher.myexam.CTestCase;
import com.huawei.classroom.teacher.myexam.QuestionTempVo;

/**
 * @author Administrator
 *
 */
public class MyScoreh07 extends AbstractMyScore {

	/**
	 * 
	 */
	public MyScoreh07(String id) {
		// TODO Auto-generated constructor stub
		super(id);
	}

	@Override
	public void doEval(QuestionTempVo vo) throws Throwable {

		// TODO Auto-generated method stub
		CTestCase t = new CTestCase(vo);

		GameBase gameBase = GameBase.createGameBase(40, 40);
		Barrack barrack = (Barrack) gameBase.building(EnumObjectType.barrack, 50, 50);

		RPGSoldier rPGSoldier1 = (RPGSoldier) barrack.traing(EnumObjectType.RPGSoldier);
		RPGSoldier rPGSoldier2 = (RPGSoldier) barrack.traing(EnumObjectType.RPGSoldier);
		RifleSoldier rifleSoldier1 = (RifleSoldier) barrack.traing(EnumObjectType.rifleSoldier);

		Dog dog1 = (Dog) barrack.traing(EnumObjectType.dog);
		Dog dog2 = (Dog) barrack.traing(EnumObjectType.dog);

		String method = "dog1.attack(dog2)";
		t.setScore(20);
		dog1.attack(dog2);
		t.setMethod(method);
		t.setPredicate((Dog h) -> h.getHealth() == 45);
		t.test(dog2);

		rPGSoldier1.move(95, 95);
		rifleSoldier1.move(100, 100);
		method = "rifleSoldier1.attack(rPGSoldier1)";
		rifleSoldier1.attack(rPGSoldier1);
		t.setMethod(method);
		t.setPredicate((RifleSoldier h) -> h.getHealth() == 50);
		t.test(rifleSoldier1);

		dog1.move(96, 97);
		method = "dog1.attack(rPGSoldier1);";
		dog1.attack(rPGSoldier1);
		dog1.attack(rPGSoldier1);
		t.setMethod(method);
		t.setPredicate((RPGSoldier h) -> h.isDestroyed());
		t.test(rPGSoldier1);

		method = "rifleSoldier1.attack(dog1);";
		rifleSoldier1.attack(dog1);
		rifleSoldier1.attack(dog1);
		t.setMethod(method);
		t.setPredicate((Dog h) -> h.isDestroyed());
		t.test(dog1);

		t.setScore(10);
		method = "Soldier.getLivingSoldierCount()";
		t.setMethod(method);
		t.setPredicate((RifleSoldier h) -> Soldier.getLivingSoldierCount() == 2);
		t.test(rifleSoldier1);

		method = "Soldier.getDeadedSoldierCount()";
		t.setMethod(method);
		t.setPredicate((RifleSoldier h) -> Soldier.getDeadedSoldierCount() == 1);
		t.test(rifleSoldier1);

	}

	public static void main(String[] args) {
		QuestionTempVo vo = new QuestionTempVo();
		try {
			new MyScoreh07("").doEval(vo);
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
