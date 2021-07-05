package com.huawei.classroom.student.h17;

public class WarFactory extends Building {

	public WarFactory(GameObjectVo vo) {
		super(vo);
		// super( Param.BARRACK_HEALTH,Param.WAR_FACTORY_STRENGTH);
		// TODO Auto-generated constructor stub
	}

	public Tank building(EnumObjectType type) {
		GameObjectVo vo = new GameObjectVo(this.getPlayer(), type, this.getX(), this.getY());
		if (type == EnumObjectType.mediumTank) {
			return new MediumTank(vo);
		} else if (type == EnumObjectType.heavyTank) {
			return new HeavyTank(vo);
		}
		return null;

	}
}
