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
 *	��ϷGUI���棬������ʾ���ݺͻ�õķ���
 */
class GameBoard:public QWidget,public Observer{
	Q_OBJECT
public:
	GameBoard(QWidget* parent =  0);
	~GameBoard();
	
	//
	void notify();

	//�����������
	void DrawBoard();

	//���̲���
	void keyPressEvent(QKeyEvent* event);

	//����ÿһ�������ϵ�����
	void DrawGrid(int i, int j);

	//���¿�ʼ��Ϸ
	void RestartGame();

	//������Ϸ
	void Continue();

private:
	//��ʼ�����еĿؼ�
	void InitWidgets();

private:
	Game* game_;

	//��Ϸ�ȼ���Ĭ��Ϊ4
	int dimension_;
	
	//��ʾ���ݵĿؼ�
	std::vector<std::vector<QLabel*>> board_;
	
	//��óɼ�
	int max_score_;

	//���ֺͿؼ�
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


	//��Ϸʧ�ܽ���
	GameOverWindow gameover_window_;
	
	//��Ϸ�ɹ�����
	GameWonWindow gamewon_window_;
};

