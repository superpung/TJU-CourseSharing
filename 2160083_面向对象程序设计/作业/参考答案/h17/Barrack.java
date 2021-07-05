package com.huawei.classroom.student.h17;

public class Barrack extends Building {

	public Barrack(GameObjectVo vo) {
		super(vo);
	}

	public GameObject traing(EnumObjectType type) {
		GameObjectVo vo = new GameObjectVo(this.getPlayer(), type, this.getX(), this.getY());
		if (type == EnumObjectType.rifleSoldier) {
			return new RifleSoldier(vo);
		} else if (type == EnumObjectType.RPGSoldier) {
			return new RPGSoldier(vo);
		} else if (type == EnumObjectType.dog) {
			return new Dog(vo);
		}
		return null;
	}

}
