package com.huawei.classroom.student.h17;

import java.util.List;

public abstract class  GameObject  {

	private int range;
	private int x;
	private int y;
	private int health = 0;
	private int defaultStrength = 0;
	private EnumObjectType objectType;
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
	
	public GameObject(GameObjectVo gameObjectVo) {
		this.player = gameObjectVo.getPlayer();
		this.x = gameObjectVo.getX();
		this.y = gameObjectVo.getY();
		this.health = gameObjectVo.getHealth();
		this.range = gameObjectVo.getRange();
		this.defaultStrength = gameObjectVo.getStrength();
		this.objectType=gameObjectVo.getEnumObjectType();
		BattleField.addGameObject(this);
	}

	public void changeHealth(int strength) {
		this.health = this.health - strength;
	}

	@Override
	public String toString() {
		return "["+player.getName() + "." + objectType +" live=" + (!isDestroyed()) + " x=" + x + " y=" + y+ " health=" + health+"]";
	}

	public int getHealth() {
		return health;
	}

	public void setHealth(int health) {
		this.health = health;
	}

	public void attack() {
		GameObject target = null;
		int minRange = Integer.MAX_VALUE;
		List<GameObject> allObject = BattleField.getAllGameObject();
		for (GameObject gameObject : allObject) {
			if ((!gameObject.getPlayer().equals(this.getPlayer())) && (!gameObject.isDestroyed())) {
				int dx = this.x - gameObject.getX();
				int dy = this.y - gameObject.getY();
				int distance = dx * dx + dy * dy;
				if(distance==minRange) {
					throw new IllegalArgumentException("dist="+distance);
				}
				if (distance < minRange&&distance<this.range*this.range) {
					target = gameObject;
					minRange=distance   ;
				}
				
			}
		}
		
		attack(target);
	}

	public void attack(GameObject obj) {
		if (obj == null) {
			return;
		}
		if (this.isDestroyed()) {
			return;
		}
		if (this.defaultStrength <= 0) {
			return;
		}
		if (obj.isDestroyed()) {
			return;
		}
		if (this.getPlayer().equals(obj.getPlayer())) {
			return;
		}

		int dx = this.x - obj.x;
		int dy = this.y - obj.y;

		if (this.range * this.range < (dx * dx + dy * dy)) {
			return;
		}
		String debug=this+" 攻击 "+obj;
		obj.changeHealth(defaultStrength);
		debug=debug+" 攻击后 health="+obj.getHealth();
		System.out.println(debug);
	}

	public boolean isDestroyed() {
		return health <= 0;
	}

	public void move(int dx, int dy) {
		if (this.isDestroyed()) {
			return;
		}
		this.x = this.x + dx;
		this.y = this.y + dy;
	}

	public int getRange() {
		return range;
	}

	public Player getPlayer() {
		return player;
	}
}
