package com.huawei.classroom.student.h17;

import java.util.ArrayList;
import java.util.List;

public class Test {

	public Test() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 某一款游戏，其主要角色如下:
		// 游戏中每个对象有当前 x,y坐标，坐标值 取值范围为整数。
		// ****每种对象的攻击力strength、攻击范围range、初始健康值health通过BattleField.init(String
		// fileName)从从配置文件中初始化
		// 非建筑物可以通过move(dx,dy)来移动坐标值,dx,dy表示x轴,y轴增量, 取值范围为整数。
		// 对象A攻击B的时候，要满足两个对象之间直线距离小于等于A的攻击范围,否则攻击无效（被攻击方不减健康值）
		// 任何对象有getHealth() 方法，返回当前生命值，如果已经死亡则返回 <=0的一个数字
		// 任何对象有isDestroyed() 方法，如果生命值<=0则true,否则false
		// GameBase 初始x,y值在创建时指定
		// Barrack 兵营，可以训练出步枪兵、 RPG兵、军犬，初始x,y值在创建时指定
		// RifleSoldier 步枪兵 ，初始x,y值就是兵营的x,y
		// RPGSoldier 火箭兵 ，初始x,y值就是兵营的x,y
		// Dog 军犬 ,初始x,y值就是兵营的x,y
		// A.attack(B)，表示A攻击B对象，B.health=B.health-A.strength 注意这次没有一击毙命方法
		// **** A.attack()，表示A寻找距离他最近、非己方、且活着的对象B 进行攻击，如果攻击范围内没有符合要求对象则什么也不做。
		// 如果A.isDestroyed() 则A.attack() 没有任何效果

		try {
			// 测试点 初始化各种战斗单元的攻击力、健康值、攻击范围。具体格式见rules.ini
			BattleField
					.init("D:\\course\\course\\exam\\src\\main\\java\\com\\huawei\\classroom\\student\\h17\\rules.ini");
			// 总共有几个玩家，测试的时候最少2个玩家，最多10个玩家
			String[] playerNames = { "A", "B", "C" };

			for (int i = 0; i < playerNames.length; i++) {
				// 测试点 传入玩家名字， 逐个创建玩家
				BattleField.createPlayer(playerNames[i]);
			}
			// 测试点 返回先前创建的所有玩家
			List<Player> players = BattleField.getAllPlayer();
			// 基地、兵工厂、兵营、坦克、士兵、狗 这些可以创建的东西必须是 GameObject 子类
			// List<GameObject> gameObjects 完全是我为了测试创建的对象，你们可以在程序里面不创建这种东西
			List<GameObject> gameObjects = new ArrayList<GameObject>();
			for (int i = 0; i < players.size(); i++) {
				// 随机确定一个基地位置
				int x = i * 100;
				int y = i * 100;
				// 测试点 传入玩家、坐标，创建基地
				GameBase base = BattleField.createGameBase(players.get(i), x, y);
				gameObjects.add(base);

				// 测试点 传入玩家、坐标，创建兵营
				Barrack barrack = (Barrack) base.building(EnumObjectType.barrack, x + 30, y + 30);
				gameObjects.add(barrack);
				// 测试点 传入玩家、坐标，创建兵工厂
				WarFactory warFactory = (WarFactory) base.building(EnumObjectType.warFactory, x + 60, y + 60);
				gameObjects.add(warFactory);

				// 创建各种战斗对象 移动位置
				gameObjects.add(barrack.traing(EnumObjectType.rifleSoldier));
				gameObjects.get(gameObjects.size() - 1).move(3, 3);
				gameObjects.add(barrack.traing(EnumObjectType.RPGSoldier));
				gameObjects.get(gameObjects.size() - 1).move(2, 2);
				gameObjects.add(barrack.traing(EnumObjectType.dog));
				gameObjects.get(gameObjects.size() - 1).move(-2, -2);

				gameObjects.add(warFactory.building(EnumObjectType.heavyTank));
				gameObjects.get(gameObjects.size() - 1).move(30, 30);
				gameObjects.add(warFactory.building(EnumObjectType.mediumTank));
				gameObjects.get(gameObjects.size() - 1).move(60, 60);

			}
			for (int round = 0; round < 5; round++) {
				for (int i = 0; i < gameObjects.size(); i++) {
					// 测试点 攻击
					gameObjects.get(i).attack();
				}
				for (int i = 0; i < gameObjects.size(); i++) {
					System.out.print(gameObjects.get(i).getHealth()+",");
				}
				System.out.println("第" + round + " 轮攻击");
			}
			//测试结果见 reuslt.txt文件 供参考
			for (int i = 0; i < gameObjects.size(); i++) {
				System.out.println(gameObjects.get(i));
			}

		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
