#include "GameWonWindow.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

GameWonWindow::GameWonWindow(QWidget* parent):QWidget(parent){
	setStyleSheet("GameOverWindow{background: rgb(237,224,200);}");
	setFixedSize(425, 300);

	QBoxLayout* layout = new QVBoxLayout(this);
	QLabel* gamewon_label = new QLabel("You Won", this);
	gamewon_label->setStyleSheet(
		"QLabel{ font:40pt bold \"Arial\";}"
	);
	

	score_label_ = new QLabel(this);
	score_label_->setStyleSheet(
		"QLabel{ color:rgb(119,110,101); font:20pt \"Arial\";}"
	);


	continue_button_ = new QPushButton("Continue", this);
	continue_button_->setFixedSize(120, 60);
	continue_button_->setStyleSheet(
		"QPushButton{background-color: rgb(143, 122, 102); border-radius:10px;font:15pt \"Arial\"; color:white; }"
	);


	restart_button_ = new QPushButton("Restart", this);
	restart_button_->setFixedSize(120, 60);
	restart_button_->setStyleSheet(
		"QPushButton{background-color: rgb(143, 122, 102); border-radius:10px;font:15pt \"Arial\"; color:white; }"
	);

	layout->insertWidget(1, gamewon_label, 0, Qt::AlignCenter);
	layout->insertWidget(2, score_label_, 0, Qt::AlignCenter);
	layout->insertWidget(3, continue_button_, 0, Qt::AlignCenter);
	layout->insertWidget(4, restart_button_, 0, Qt::AlignCenter);
}


GameWonWindow::~GameWonWindow(){

}



QLabel* GameWonWindow::GetScoreLabel() {
	return score_label_;
}

QPushButton* GameWonWindow::GetContinueButton() {
	return continue_button_;
}

QPushButton* GameWonWindow::GetRestartButton() {
	return restart_button_;
}