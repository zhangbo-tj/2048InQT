#pragma once

#include <QWidget>

class QLabel;
class QPushButton;

class GameWonWindow:public QWidget{
	Q_OBJECT
public:
	explicit GameWonWindow(QWidget* parent = 0);
	~GameWonWindow();

	QLabel* GetScoreLabel();
	QPushButton* GetContinueButton();
	QPushButton* GetRestartButton();
	
private:
	QLabel* score_label_;
	QPushButton* continue_button_;
	QPushButton* restart_button_;
};

