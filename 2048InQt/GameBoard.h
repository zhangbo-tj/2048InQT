#pragma once


#include <vector>
#include <QWidget>

#include "Game.h"
#include "Observer.h"
#include "GameOverWindow.h"
#include "GameWonWindow.h"

class QKeyEvent;
class QGridLayout;
class QLabel;
class QGroupBox;
class QHBoxLayout;
class QVBoxLayout;
class QPushButton;


/*
 *	游戏GUI界面，包括显示数据和获得的分数
 */
class GameBoard:public QWidget,public Observer{
	Q_OBJECT
public:
	GameBoard(QWidget* parent =  0);
	~GameBoard();
	
	//
	void notify();

	//绘制数据面板
	void DrawBoard();

	//键盘操作
	void keyPressEvent(QKeyEvent* event);

	//绘制每一个网格上的数据
	void DrawGrid(int i, int j);

	//重新开始游戏
	void RestartGame();

	//继续游戏
	void Continue();

private:
	//初始化所有的控件
	void InitWidgets();

private:
	Game* game_;

	//游戏等级，默认为4
	int dimension_;
	
	//显示数据的控件
	std::vector<std::vector<QLabel*>> board_;
	
	//最好成绩
	int max_score_;

	//布局和控件
	QVBoxLayout* main_layout_;
	QGridLayout* board_layout_;

	QGridLayout* panel_layout;
	QLabel* game_title_label_;
	QGroupBox* maxscore_groupbox_;
	QHBoxLayout* maxscore_layout_;
	QLabel* maxscore_title_label_;
	QLabel* maxscore_value_label_;

	QGroupBox* curscore_groupbox_;
	QHBoxLayout* curscore_layout_;
	QLabel* curscore_title_label_;
	QLabel* curscore_value_label_;


	//游戏失败界面
	GameOverWindow gameover_window_;
	
	//游戏成功界面
	GameWonWindow gamewon_window_;
};

