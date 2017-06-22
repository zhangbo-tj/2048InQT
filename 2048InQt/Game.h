#pragma once

#include <vector>

#include "Subject.h"

/*
 *	移动方向，只能为上、下、左、右四个方向
 */
enum Direction {
	LEFT = 1,
	RIGHT = 2,
	UP = 3,
	DOWN = 4
};


/*
 *	目标类，用于保存数据以及计算每次操作后的结果
 */
class Game:public Subject
{
public:
	Game(int dim = 4);
	~Game();

	//重新开始
	void Restart();

	//判断游戏是否失败
	bool IsGameOver() const { return over_; }
	
	//移动操作，
	void Move(Direction dir);

	//判断游戏是否胜利
	bool Won()const;

	//获取当前分数
	int GetScore()const { return score_; }

	//移动操作的具体实现函数，分别向四个方向移动
	bool MoveLeft();
	bool MoveRight();
	bool MoveUp();
	bool MoveDown();

	//在空缺位置随机生成数字2
	void RandomGenerate();

	//判断当前的数字是否已经填满
	bool Full();

	//获取点（i,j）的数值
	int GetValue(int i, int j);
	
	//判断两个二维数据是否相同
	bool Changed(std::vector<std::vector<int>>& vec1, std::vector<std::vector<int>>& vec2);

	//在游戏已经成功后，继续游戏
	void SetContinue();

	//是否还存在可行解
	bool MovePossible();

private:
	//游戏数据
	std::vector<std::vector<int>> data_;
	
	//游戏是否已经结束
	bool over_;

	//当前分数
	int score_;

	//游戏画面尺寸，即dimension * dimension
	int dimension_;
	
	//是否在游戏成功后继续游戏
	bool continued_;
};

