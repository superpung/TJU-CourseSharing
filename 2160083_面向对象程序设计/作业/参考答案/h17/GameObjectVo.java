package com.huawei.classroom.student.h17;

public class GameObjectVo {
	public EnumObjectType getEnumObjectType() {
		return enumObjectType;
	}

	public void setEnumObjectType(EnumObjectType enumObjectType) {
		this.enumObjectType = enumObjectType;
	}

	public Player getPlayer() {
		return player;
	}

	public void setPlayer(Player player) {
		this.player = player;
	}

	private int x;
	private int y;
	private int health;
	private int strength;
	private int range;
	private EnumObjectType enumObjectType;
	private Player player;
	

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getHealth() {
		return health;
	}

	public void setHealth(int health) {
		this.health = health;
	}

	public int getStrength() {
		return strength;
	}

	public void setStrength(int strength) {
		this.strength = strength;
	}

	public int getRange() {
		return range;
	}

	public void setRange(int range) {
		this.range = range;
	}

	public GameObjectVo(Player player,EnumObjectType enumObjectType,int x,int y) {
		this.enumObjectType = enumObjectType;
		this.health = BattleField.getParam().getIntParam(enumObjectType, Param.HEALTH);
		this.range = BattleField.getParam().getIntParam(enumObjectType, Param.RANGE);
		this.strength = BattleField.getParam().getIntParam(enumObjectType, Param.STRENGTH);
		this.x=x;
		this.y=y;
		this.player=player;
		// TODO Auto-generated constructor stub
	}

}
