#include "GameOverWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>


/*
 *	游戏失败界面
 */
GameOverWindow::GameOverWindow(QWidget* parent):QWidget(parent){
	setStyleSheet("GameOverWindow{background: rgb(237,224,200);}");
	setFixedSize(425, 200);


	//初始化控件
	QVBoxLayout* layout = new QVBoxLayout(this);
	QLabel* gameover_label = new QLabel("Game Over", this);
	gameover_label->setStyleSheet(
		"QLabel{ font:40pt bold \"Arial\";}"
	);
	
	score_label_ = new QLabel(this);
	score_label_->setStyleSheet("QLabel{color:rgb(119,110,101);font:20pt \"Arial\";}");

	reset_button_ = new QPushButton("Try Again",this);
	reset_button_->setFixedSize(120, 60);
	reset_button_->setStyleSheet(
		"QPushButton{background-color: rgb(143, 122, 102); border-radius:10px;font:15pt \"Arial\"; color:white; }"
	);

	layout->insertWidget(1, gameover_label, 0, Qt::AlignCenter);
	layout->insertWidget(2, score_label_, 0, Qt::AlignCenter);
	layout->insertWidget(3, reset_button_, 0, Qt::AlignCenter);

}


/*
 *	析构函数
 */
GameOverWindow::~GameOverWindow(){

}


/*
 *	获取重新开始游戏按钮
 */
QPushButton* GameOverWindow::GetResetButton()const {
	return reset_button_;
}


/*
 *	获取分数标签
 */
QLabel* GameOverWindow::GetScoreLabel() {
	return score_label_;
}

