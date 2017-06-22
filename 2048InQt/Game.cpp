#include "Game.h"

#include <random>

/*
 *	���캯��
 */
Game::Game(int dim):dimension_(dim),score_(0),continued_(false),over_(false){
	data_.resize(dim);
	for (auto& d : data_) {
		d.resize(dim,0);
	}
}


/*
 *	��������
 */
Game::~Game(){

}


/*
 *	���¿�ʼ��Ϸ����Ҫ�������в���
 */
void Game::Restart() {
	for (auto& d : data_) {
		for (auto& num : d) {
			num = 0;
		}
	}
	RandomGenerate();
	RandomGenerate();
	over_ = false;
	score_ = 0;
	continued_ = false;
}


/*
 *	�û��ƶ��������ֱ��ϡ��¡������ĸ�����
 */
void Game::Move(Direction dir) {
	//���û�п��н⣬��Ϸ����
	if (!MovePossible()) {
		over_ = true;
		NotifyObservers();
		return;
	}

	//�ж��û�����֮�������Ƿ�ı�
	bool moved = false;
	switch (dir)
	{
	case LEFT:
		moved = MoveLeft();
		break;
	case RIGHT:
		moved = MoveRight();
		break;
	case UP:
		moved = MoveUp();
		break;
	case DOWN:
		moved = MoveDown();
		break;
	default:
		break;
	}

	//������ݸı䣬��֪ͨ�۲���
	if (moved) {
		RandomGenerate();
		NotifyObservers();
	}
}


/*
 *	�ж��Ƿ�õ�2048
 */
bool Game::Won()const {
	//�����ǰ״̬�ǳɹ�֮�������Ϸ����û�гɹ�
	if (continued_ == true)	return false;

	// �ж��Ƿ�õ�2048
	for (int i = 0; i < data_.size(); i++) {
		for (auto num : data_[i]) {
			if (num == 2048) {
				return true;
			}
		}
	}
	return false;
}


/*
 *	�����ƶ���ʹ��˫ָ������ƶ���Ľ��
 */
bool Game::MoveLeft() {
	std::vector<std::vector<int>> tmp = data_;
	for (int r = 0; r < dimension_; r++) {
		for (int left = 0, right = 0; right < dimension_; right++) {
			if(left != right && data_[r][right]) {
				int val = data_[r][right];
				data_[r][right] = 0;
				if (data_[r][left] == 0) {
					data_[r][left] = val;
				}
				else if (data_[r][left] == val) {
					data_[r][left++] *= 2;
					score_ += val * 2;
				}
				else {
					data_[r][++left] = val;
				}
			}
		}
	}
	return Changed(tmp, data_);
}


/*
 *	�����˶���ʹ��˫ָ������ƶ���Ľ��
 */
bool Game::MoveRight() {
	std::vector<std::vector<int>> tmp = data_;
	for (int r = 0; r < dimension_; r++) {
		for (int left = dimension_ - 1, right = dimension_ - 1; left >= 0; left--) {
			if(left != right && data_[r][left]) {
				int val = data_[r][left];
				data_[r][left] = 0;
				if (data_[r][right] == 0) {
					data_[r][right] = val;
				}
				else if (data_[r][right] == val) {
					data_[r][right--] *= 2;
					score_ += val * 2;
				}
				else {
					data_[r][--right] = val;
				}
			}
		}
	}
	return Changed(tmp, data_);
}


/*
 *	�����ƶ���ʹ��˫ָ������ƶ���Ľ��
 */
bool Game::MoveUp() {
	std::vector<std::vector<int>> tmp = data_;
	for (int c = 0; c < dimension_; c++) {
		for (int up = 0, down = 0; down < dimension_; down++) {
			if (up != down && data_[down][c]) {
				int val = data_[down][c];
				data_[down][c] = 0;
				if (data_[up][c] == 0) {
					data_[up][c] = val;
				}
				else if (data_[up][c] == val) {
					data_[up++][c] *= 2;
					score_ += val * 2;
				}
				else {
					data_[++up][c] = val;
				}
			}
		}
	}
	return Changed(tmp, data_);
}


/*
 *	�����ƶ���ʹ��˫ָ������ƶ���Ľ��
 */
bool Game::MoveDown() {
	std::vector<std::vector<int>> tmp = data_;
	for (int c = 0; c < dimension_; c++) {
		for (int up = dimension_ - 1, down = dimension_ - 1; up >= 0; up--) {
			if (up != down && data_[up][c]) {
				int val = data_[up][c];
				data_[up][c] = 0;
				if (data_[down][c] == 0) {
					data_[down][c] = val;
				}
				else if (data_[down][c] == val) {
					data_[down--][c] *= 2;
					score_ += val * 2;
				}
				else {
					data_[--down][c] = val;
				}
			}
		}
	}
	return Changed(tmp, data_);
}


/*
 *	�жϵ�ǰ�������Ƿ�ȫ��Ϊ0
 */
bool Game::Full(){
	for (int i = 0; i < dimension_; i++) {
		for (int j = 0; j < dimension_; j++) {
			if (data_[i][j] == 0) { return false; }
		}
	}
	return true;
}



/*
 *	�������в�Ϊ0��λ�����������һ������2
 */
void Game::RandomGenerate() {
	if (Full()) return;
	
	int i = 0, j = 0;
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> u(0, dimension_-1);
	do {
		i = u(gen);
		j = u(gen);
	} while (data_[i][j] != 0);

	data_[i][j] = 2;
}


/*
 *	��ȡ�����У�i��j��λ���ϵ���ֵ
 */
int Game::GetValue(int i, int j) {
	return data_[i][j];
}


/*
 *	�ж�������ά�����Ƿ���ͬ
 */
bool Game::Changed(std::vector<std::vector<int>>& vec1, std::vector<std::vector<int>>& vec2) {
	for (int i = 0; i < dimension_; i++) {
		for (int j = 0; j < dimension_; j++) {
			if (vec1[i][j] != vec2[i][j]) {
				return true;
			}
		}
	}
	return false;
}


/*
 *	��Ϸ�ɹ��������Ϸ�����ñ�־λ
 */
void Game::SetContinue() {
	continued_ = true;
}


/*
 *	�ж���Ϸ��ǰ�Ƿ��п��н�
 */
bool Game::MovePossible() {
	//�������û�����������п��н�
	if (!Full()) return true;

	//��������Ѿ������������ж����ĸ������ƶ���������Ƿ����ı�
	std::vector<std::vector<int>>  tmp = data_;
	if (MoveLeft()) {
		data_ = tmp;
		return true;
	}
	if (MoveRight()) {
		data_ = tmp;
		return true;
	}
	if (MoveUp()) {
		data_ = tmp;
		return true;
	}
	if (MoveDown()) {
		data_ = tmp;
		return true;
	}
	return false;
}