package com.huawei.classroom.student.h17;

import java.util.ArrayList;
import java.util.List;

public class Player {
	
	private String name;
	
	public Player(String name ) { 
		this.name = name; 
	}

	private List<GameObject> gameObjectList = new ArrayList<GameObject>();

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public List<GameObject> getGameObjectList() {
		return gameObjectList;
	}

	public void addGameObject(GameObject gameObject) {
		gameObjectList.add(gameObject);
	}

	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		if(obj instanceof Player) {
			return this.name.endsWith(((Player)obj).getName());
		}else {
			return false;
		}
	}
 
}