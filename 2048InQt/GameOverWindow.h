#pragma once

#include <QWidget>


class QPushButton;
class QLabel;


/*
 *	游戏失败界面，包括获得的分数以及重新开始游戏按钮
 */
class GameOverWindow:public QWidget{
	Q_OBJECT
public:
	explicit GameOverWindow(QWidget* parent = 0);
	~GameOverWindow();

	QPushButton* GetResetButton() const;
	QLabel* GetScoreLabel();

private:
	//重新开始游戏按钮
	QPushButton* reset_button_;

	//分数标签
	QLabel* score_label_;
};

