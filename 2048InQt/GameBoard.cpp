#include "GameBoard.h"

#include <QKeyEvent>
#include <QGraphicsDropShadowEffect>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>


/*
 *	���캯������ʼ���ؼ����������صĲ���
 */
GameBoard::GameBoard(QWidget* parent):QWidget(parent),max_score_(0),dimension_(4){
	setFocusPolicy(Qt::TabFocus);
	
	//��ʼ����Ϸ
	game_ = new Game(dimension_);
	game_->RandomGenerate();
	game_->RandomGenerate();
	game_->RegisterObserver(this);

	//��ʼ���ؼ�
	board_.resize(dimension_);
	for (int i = 0; i < dimension_; i++) {
		board_[i].clear();
		for (int j = 0; j < dimension_; j++) {
			board_[i].push_back(new QLabel());
		}
	}
	InitWidgets();

	//�������е����ݱ�ǩ
	DrawBoard();

	setStyleSheet(QString("QGameBoard{background-color: rgb{187,173,160}}"));

	connect(gameover_window_.GetResetButton(), &QAbstractButton::clicked, this, &GameBoard::RestartGame);
	connect(gamewon_window_.GetContinueButton(), &QAbstractButton::clicked, this, &GameBoard::Continue);
	connect(gamewon_window_.GetRestartButton(), &QPushButton::clicked, this, &GameBoard::RestartGame);
}



/*
 *	��������
 */
GameBoard::~GameBoard(){
	delete game_;
	for (int i = 0; i < dimension_; i++) {
		for (int j = 0; j < dimension_; j++) {
			delete board_[i][j];
		}
	}
}


/*
 *	���̲������û�ͨ�����̲�����Ϸ
 */
void GameBoard::keyPressEvent(QKeyEvent* event) {
	switch (event->key())	{
	case Qt::Key_Up:
		game_->Move(Direction::UP);
		break;
	case Qt::Key_Down:
		game_->Move(Direction::DOWN);
		break; 
	case Qt::Key_Left:
		game_->Move(Direction::LEFT);
		break;
	case Qt::Key_Right:
		game_->Move(Direction::RIGHT);
		break;
	default:
		break;
	}
}



/*
 *	���µ�ǰҳ������
 */
void GameBoard::notify() {
	int cur_score = game_->GetScore();
	max_score_ = max_score_ > cur_score ? max_score_ : cur_score;
	maxscore_value_label_->setText(QString::number(max_score_));
	curscore_value_label_->setText(QString::number(cur_score));
	
	//�����Ϸʧ�ܣ�����ʾ��Ϸʧ��ҳ��
	if (game_->IsGameOver()) {
		gameover_window_.show();
		gameover_window_.GetScoreLabel()->setText(QString("Score: %1").arg(max_score_));
	}
	//�����Ϸ�ɹ����򷵻���Ϸ�ɹ�����
	else if (game_->Won()) {
		gamewon_window_.show();
		gamewon_window_.GetScoreLabel()->setText(QString("Score:%1").arg(max_score_));
	}
	DrawBoard();
}


/*
 *	��ʾ��Ϸ����
 */
void GameBoard::DrawBoard() {
	for (int i = 0; i < dimension_; i++) {
		for (int j = 0; j < dimension_; j++) {
			DrawGrid(i, j);
		}
	}
}


/*
 *	�ֱ����ÿһ�����ݱ�ǩ
 */
void GameBoard::DrawGrid(int i, int j) {
	int val = game_->GetValue(i, j);
	
	if (val == 0) {
		board_[i][j]->setText("");
		board_[i][j]->setStyleSheet("QLabel { background: rgb(204,192,179); border-radius: 10px; }");
	}
	else {
		board_[i][j]->setText(QString::number(val));
		switch (val) {
		case 2: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 4: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 8: {
			board_[i][j]->setStyleSheet("QLabel { qproperty-alignment:AlignCenter;background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 16: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 32: {
			board_[i][j]->setStyleSheet("QLabel { qproperty-alignment:AlignCenter; background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 64: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 128: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 256: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 512: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 1024: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		case 2048: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}
		default: {
			board_[i][j]->setStyleSheet("QLabel {qproperty-alignment:AlignCenter; background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
			break;
		}

		}
	}
}


/*
 *	��ʼ����Ϸҳ��Ŀؼ�
 */
void GameBoard::InitWidgets() {
	game_title_label_ = new QLabel(QString::fromLocal8Bit("2048"));
	game_title_label_->setStyleSheet(
		"QLabel{background:rgb(231, 186, 0);color:rgb(255, 255, 255);font: bold 40pt \"Arial\";qproperty-alignment:AlignCenter;border-radius:5px; margin:10px;}"
	);

	maxscore_groupbox_ = new QGroupBox();
	maxscore_groupbox_->setStyleSheet("QGroupBox{ background:rgb(172, 156, 141); border-radius:5px; margin:5px;}");
	
	maxscore_title_label_ = new QLabel(QString::fromLocal8Bit("��ʷ��߳ɼ�"));
	maxscore_title_label_->setStyleSheet(QString("QLabel{qproperty-alignment:AlignCenter;font:bold 15pt \"΢���ź�\";}"));
	
	maxscore_value_label_ = new QLabel();
	maxscore_value_label_->setStyleSheet("QLabel{ color:rgb(255, 255, 255); font:20pt \"Arial\"; qproperty-alignment:AlignCenter;}");

	curscore_groupbox_ = new QGroupBox();
	curscore_groupbox_->setStyleSheet("QGroupBox{ background:rgb(172, 156, 141); border-radius:5px; margin:5px;}");

	curscore_title_label_ = new QLabel(QString::fromLocal8Bit("��ǰ����"));
	curscore_title_label_->setStyleSheet("QLabel{font:bold 15pt \"΢���ź�\";qproperty-alignment:AlignCenter;}");

	curscore_value_label_ = new QLabel();
	curscore_value_label_->setStyleSheet("QLabel{ color:rgb(255, 255, 255); font:20pt \"Arial\"; qproperty-alignment:AlignCenter;}");

	maxscore_layout_ = new QHBoxLayout();
	maxscore_layout_->addWidget(maxscore_title_label_,2);
	maxscore_layout_->addWidget(maxscore_value_label_,1);
	maxscore_groupbox_->setLayout(maxscore_layout_);

	curscore_layout_ = new QHBoxLayout();
	curscore_layout_->addWidget(curscore_title_label_,2);
	curscore_layout_->addWidget(curscore_value_label_,1);
	curscore_groupbox_->setLayout(curscore_layout_);

	panel_layout = new QGridLayout();
	panel_layout->setColumnStretch(0, 1);
	panel_layout->setColumnStretch(1, 1);
	panel_layout->addWidget(game_title_label_, 0, 0, 2, 1);
	panel_layout->addWidget(maxscore_groupbox_, 0, 1);
	panel_layout->addWidget(curscore_groupbox_, 1, 1);


	

	board_layout_ = new QGridLayout();
	for (int i = 0; i < dimension_; i++) {
		for (int j = 0; j < dimension_; j++) {
			board_layout_->addWidget(board_[i][j], i, j);
		}
	}

	main_layout_ = new QVBoxLayout();
	main_layout_->addLayout(panel_layout,1);
	main_layout_->addLayout(board_layout_,4);
	setLayout(main_layout_);
}


/*
 *	���¿�ʼ��Ϸ
 */
void GameBoard::RestartGame() {
	game_->Restart();
	DrawBoard();
	gameover_window_.hide();
	gamewon_window_.hide();
}


/*
 *	������Ϸ
 */
void GameBoard::Continue() {
	game_->SetContinue();
	gamewon_window_.hide();
}