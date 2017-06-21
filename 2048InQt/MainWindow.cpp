#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	resize(800, 800);
	game_board_ = new GameBoard(this);
	setCentralWidget(game_board_);
}


MainWindow::~MainWindow(){
	delete game_board_;
}