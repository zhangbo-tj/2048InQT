#pragma once

#include <QWidget>


class QPushButton;
class QLabel;

class GameOverWindow:public QWidget{
	Q_OBJECT
public:
	explicit GameOverWindow(QWidget* parent = 0);
	~GameOverWindow();

	QPushButton* GetResetButton() const;
	QLabel* GetScoreLabel();

private:
	QPushButton* reset_button_;
	QLabel* score_label_;
};

