#pragma once

#include <vector>

#include "Subject.h"

/*
 *	�ƶ�����ֻ��Ϊ�ϡ��¡������ĸ�����
 */
enum Direction {
	LEFT = 1,
	RIGHT = 2,
	UP = 3,
	DOWN = 4
};


/*
 *	Ŀ���࣬���ڱ��������Լ�����ÿ�β�����Ľ��
 */
class Game:public Subject
{
public:
	Game(int dim = 4);
	~Game();

	//���¿�ʼ
	void Restart();

	//�ж���Ϸ�Ƿ�ʧ��
	bool IsGameOver() const { return over_; }
	
	//�ƶ�������
	void Move(Direction dir);

	//�ж���Ϸ�Ƿ�ʤ��
	bool Won()const;

	//��ȡ��ǰ����
	int GetScore()const { return score_; }

	//�ƶ������ľ���ʵ�ֺ������ֱ����ĸ������ƶ�
	bool MoveLeft();
	bool MoveRight();
	bool MoveUp();
	bool MoveDown();

	//�ڿ�ȱλ�������������2
	void RandomGenerate();

	//�жϵ�ǰ�������Ƿ��Ѿ�����
	bool Full();

	//��ȡ�㣨i,j������ֵ
	int GetValue(int i, int j);
	
	//�ж�������ά�����Ƿ���ͬ
	bool Changed(std::vector<std::vector<int>>& vec1, std::vector<std::vector<int>>& vec2);

	//����Ϸ�Ѿ��ɹ��󣬼�����Ϸ
	void SetContinue();

	//�Ƿ񻹴��ڿ��н�
	bool MovePossible();

private:
	//��Ϸ����
	std::vector<std::vector<int>> data_;
	
	//��Ϸ�Ƿ��Ѿ�����
	bool over_;

	//��ǰ����
	int score_;

	//��Ϸ����ߴ磬��dimension * dimension
	int dimension_;
	
	//�Ƿ�����Ϸ�ɹ��������Ϸ
	bool continued_;
};

