#pragma once


#include <vector>

#include <QLabel>
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

class GameBoard:public QWidget,public Observer{
	Q_OBJECT
public:
	GameBoard(QWidget* parent =  0);
	~GameBoard();

	void notify();

	void DrawBoard();

	void keyPressEvent(QKeyEvent* event);

	void DrawGrid(int i, int j);

	void RestartGame();

	void Continue();

private:
	void InitWidgets();

private:
	Game* game_;
	int dimension_;
	
	std::vector<std::vector<QLabel*>> board_;
	int max_score_;


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


	GameOverWindow gameover_window_;
	GameWonWindow gamewon_window_;
};

