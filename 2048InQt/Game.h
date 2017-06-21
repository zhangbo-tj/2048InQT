#pragma once

#include <vector>

#include "Subject.h"

enum Direction {
	LEFT = 1,
	RIGHT = 2,
	UP = 3,
	DOWN = 4
};

class Game:public Subject
{
public:
	Game(int dim = 4);
	~Game();
	void Restart();
	bool IsGameOver() const { return over_; }
	void Move(Direction dir);

	bool Won()const;
	int GetScore()const { return score_; }

	bool MoveLeft();
	bool MoveRight();
	bool MoveUp();
	bool MoveDown();
	void RandomGenerate();
	bool Full();

	int GetValue(int i, int j);
	bool Changed(std::vector<std::vector<int>>& vec1, std::vector<std::vector<int>>& vec2);

	void SetContinue();

	bool MovePossible();

private:
	std::vector<std::vector<int>> data_;
	bool over_;
	int score_;
	int dimension_;
	
	bool continued_;
};

