package com.huawei.classroom.student.h17;

public class GameBase extends GameObject {
	
	
	public GameBase(GameObjectVo vo) {
		super(vo);
	}

	public Building building(EnumObjectType type, int x, int y) {
		GameObjectVo vo = new GameObjectVo(this.getPlayer(), type, x, y);

		if (type == EnumObjectType.barrack) {
			return new Barrack(vo);
		} else if (type == EnumObjectType.warFactory) {
			return new WarFactory(vo);
		}
		return null;

	}
}
