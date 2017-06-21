# 2048InQT
> 该项目是使用C++/Qt开发的2048游戏，项目借鉴了[jvaelen](https://github.com/jvaelen/2048)的程序，但是在其基础上进行了逻辑和GUI的改进。
>
> 游戏的逻辑部分是用C++实现的，GUI部分没有用Qt Designer而是直接用代码实现的。
> 
> 项目采用了观察者模式，将数据和GUI分离开。
>
>逻辑部分改进：1.判断移动后的效果部分;  2.在完成2048后可选择继续或重新开始; 3.记录最好成绩
>
>界面部分改进： 1. 游戏失败和成功时显示当前(最好)成绩; 2. 显示最好成绩和当前局的成绩

## 程序截图
### 游戏开始界面
>![游戏开始界面](https://github.com/zhangbo-tj/2048InQT/raw/master/screenshot/gamestart.png)
>
### 游戏失败界面
>![游戏失败界面](https://github.com/zhangbo-tj/2048InQT/raw/master/screenshot/gameover.png)
>
### 游戏成功界面
>![游戏成功界面](https://github.com/zhangbo-tj/2048InQT/raw/master/screenshot/gamewon.png)
