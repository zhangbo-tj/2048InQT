#pragma once

#include <QWidget>


class QPushButton;
class QLabel;


/*
 *	��Ϸʧ�ܽ��棬������õķ����Լ����¿�ʼ��Ϸ��ť
 */
class GameOverWindow:public QWidget{
	Q_OBJECT
public:
	explicit GameOverWindow(QWidget* parent = 0);
	~GameOverWindow();

	QPushButton* GetResetButton() const;
	QLabel* GetScoreLabel();

private:
	//���¿�ʼ��Ϸ��ť
	QPushButton* reset_button_;

	//������ǩ
	QLabel* score_label_;
};

