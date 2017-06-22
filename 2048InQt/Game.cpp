#include "Game.h"

#include <random>

/*
 *	构造函数
 */
Game::Game(int dim):dimension_(dim),score_(0),continued_(false),over_(false){
	data_.resize(dim);
	for (auto& d : data_) {
		d.resize(dim,0);
	}
}


/*
 *	析构函数
 */
Game::~Game(){

}


/*
 *	重新开始游戏，需要重置所有参数
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
 *	用户移动操作，分别上、下、左、右四个方向
 */
void Game::Move(Direction dir) {
	//如果没有可行解，游戏结束
	if (!MovePossible()) {
		over_ = true;
		NotifyObservers();
		return;
	}

	//判断用户操作之后数据是否改变
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

	//如果数据改变，则通知观察者
	if (moved) {
		RandomGenerate();
		NotifyObservers();
	}
}


/*
 *	判断是否得到2048
 */
bool Game::Won()const {
	//如果当前状态是成功之后继续游戏，则没有成功
	if (continued_ == true)	return false;

	// 判断是否得到2048
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
 *	向左移动，使用双指针计算移动后的结果
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
 *	向右运动，使用双指针计算移动后的结果
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
 *	向上移动，使用双指针计算移动后的结果
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
 *	向下移动，使用双指针计算移动后的结果
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
 *	判断当前的数字是否全不为0
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
 *	在数组中不为0的位置上随机生成一个数字2
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
 *	获取数组中（i，j）位置上的数值
 */
int Game::GetValue(int i, int j) {
	return data_[i][j];
}


/*
 *	判断两个二维数组是否相同
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
 *	游戏成功后继续游戏，设置标志位
 */
void Game::SetContinue() {
	continued_ = true;
}


/*
 *	判断游戏当前是否还有可行解
 */
bool Game::MovePossible() {
	//如果数据没有填满，则还有可行解
	if (!Full()) return true;

	//如果数据已经被填满，则判断向四个方向移动后的数据是否发生改变
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