#pragma once

#include <QtWidgets/QMainWindow>
#include "GameBoard.h"
//#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	//Ui::MainWindowClass ui;
	GameBoard* game_board_;
};
