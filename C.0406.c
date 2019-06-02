//三子棋
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Max_Row 3
#define Max_Col 3

char chess_board[Max_Row][Max_Col];
//运行界面
int Menu(){
	printf("*******************\n");
	printf("*******************\n");
	printf("****1、开始游戏****\n");
	printf("****0、结束游戏****\n");
	printf("*******************\n");
	printf("*******************\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Make(){
	//x表示玩家落棋，o表示电脑落棋,“ ”表示没有落棋
	for (int row = 0; row < Max_Row; ++row){
		for (int col = 0; col < Max_Col; ++col){
			chess_board[row][col]=' ';
		}
	}
}

void Print(){
	//打印棋盘
	int row = 0;
	for (row = 0; row < Max_Row; ++row){
		printf("| %c | %c | %c |\n",
			chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		if (row != Max_Row - 1){
			printf("|---|---|---|\n");
		}
	}
}

void Player(){
	printf("玩家请落棋!\n");
	while (1){
		printf("请输入下棋的坐标（row col）:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= Max_Row || col >= Max_Col||row<0||col<0){
			printf("傻子，输入有误！\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("您的选择已被占用！\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
//检查棋盘是否满
int IsFull(){
	for (int row = 0; row < Max_Row; ++row){
		for (int col = 0; col < Max_Col; ++col){
			if (chess_board[row][col] == ' '){
				return 0;
			}	
		}
	}
	return 1;
}

char CheckGameover(){
	//检查行；
	for (int row = 0; row < Max_Row; ++row){
		if (chess_board[row][0] == chess_board[row][1]
			&& chess_board[row][0] == chess_board[row][2])
			return chess_board[row][0];
	}
	//检查列；
	for (int col = 0; col < Max_Col; ++col){
		if (chess_board[0][col] == chess_board[1][col]
			&& chess_board[0][col] == chess_board[2][col])
			return chess_board[0][col];
	}
	//检查对角线
	if (chess_board[0][0] == chess_board[1][1]
		&& chess_board[0][0] == chess_board[2][2]){
		return chess_board[1][1];
	}
	if (chess_board[0][2] == chess_board[1][1]
		&& chess_board[0][2] == chess_board[2][0]){
		return chess_board[1][1];
	}
	if (IsFull()){
		return 'w';
	}
	return ' ';
}

void Computer(){
	printf("电脑请下棋！\n");
	while (1){
		int row = rand() % Max_Row;
		int col = rand() % Max_Col;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}

void start(){
	//1、创建3*3棋盘；
	Make();
	char winner = ' ';
	while (1){
		system("cls");
		//2、打印棋盘；
		Print();
		//3、玩家下棋；
		Player();
		//4、检验游戏是否结束；
		winner=CheckGameover();
		if (winner != ' '){
			break;
		}
		//5、电脑下棋；
		Computer();
		//6、检验游戏是否结束；
		winner=CheckGameover();
		if (winner != ' '){
			break;
		}
	}
	system("cls");
	//winner = CheckGameover();
	if (winner == 'x'){
		printf("您真厉害！\n");
	}
	else if (winner == 'o'){
		printf("您没有电脑厉害！\n");
	}
	else if (winner == 'w'){
		printf("您和电脑一样厉害！\n");
	}
	else{
		printf("系统出错！\n");
	}
	
}

int main(){
	while(1){
		int choice = Menu();
		if (choice == 1){
			//开始游戏
			start();
		}
		else if (choice == 0){
			//结束游戏
			printf("游戏结束！\n");
			break;
		}
		else{
			printf("您的输入有误！\n");
		}
	}
	system("pause");
	return 0;
}