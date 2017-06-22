#pragma once

#include <QWidget>

class QLabel;
class QPushButton;


/*
 *	��Ϸ�ɹ����棬��ʾ��õķ����Լ�������Ϸ��ť�����¿�ʼ��Ϸ��ť
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
	//��÷����ı�ǩ
	QLabel* score_label_;
	//������Ϸ��ť
	QPushButton* continue_button_;
	//���¿�ʼ��Ϸ��ť
	QPushButton* restart_button_;
};

