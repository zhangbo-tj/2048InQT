#pragma once

#include <QWidget>

class QLabel;
class QPushButton;


/*
 *	游戏成功界面，显示获得的分数以及继续游戏按钮和重新开始游戏按钮
 */
class GameWonWindow:public QWidget{
	Q_OBJECT
public:
	explicit GameWonWindow(QWidget* parent = 0);
	~GameWonWindow();

	QLabel* GetScoreLabel();
	QPushButton* GetContinueButton();
	QPushButton* GetRestartButton();
	
private:
	//获得分数的标签
	QLabel* score_label_;
	//继续游戏按钮
	QPushButton* continue_button_;
	//重新开始游戏按钮
	QPushButton* restart_button_;
};

