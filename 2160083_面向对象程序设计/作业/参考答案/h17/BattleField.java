package com.huawei.classroom.student.h17;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class BattleField {
	private static Param param=null;
	private static List<Player> allPlayer=new ArrayList<Player>();
	private static List<GameObject> allGameObjectList = new ArrayList<GameObject>();

	public static void init(String config) throws FileNotFoundException, IOException {
		param=new Param(config);
	}
	public static Param getParam() {
		return param;
	} 

	public static List<Player> getAllPlayer() {
		return allPlayer;
	}
	public static List<GameObject> getAllGameObject(){
		return allGameObjectList;
	}
	public static void addGameObject(GameObject gameObject) {
		allGameObjectList.add(gameObject);
	}
	
	public static Player createPlayer(String name) {
		Player player=new Player(name);
		allPlayer.add(player);
		return player; 
	}

	public static GameBase createGameBase(Player player,int x,int y) {
		GameObjectVo gameObjectVo=new  GameObjectVo(player,EnumObjectType.base,x,y);
		return new GameBase(gameObjectVo);
	}
}
