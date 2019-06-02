//������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Max_Row 3
#define Max_Col 3

char chess_board[Max_Row][Max_Col];
//���н���
int Menu(){
	printf("*******************\n");
	printf("*******************\n");
	printf("****1����ʼ��Ϸ****\n");
	printf("****0��������Ϸ****\n");
	printf("*******************\n");
	printf("*******************\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Make(){
	//x��ʾ������壬o��ʾ��������,�� ����ʾû������
	for (int row = 0; row < Max_Row; ++row){
		for (int col = 0; col < Max_Col; ++col){
			chess_board[row][col]=' ';
		}
	}
}

void Print(){
	//��ӡ����
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
	printf("���������!\n");
	while (1){
		printf("��������������꣨row col��:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= Max_Row || col >= Max_Col||row<0||col<0){
			printf("ɵ�ӣ���������\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("����ѡ���ѱ�ռ�ã�\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
//��������Ƿ���
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
	//����У�
	for (int row = 0; row < Max_Row; ++row){
		if (chess_board[row][0] == chess_board[row][1]
			&& chess_board[row][0] == chess_board[row][2])
			return chess_board[row][0];
	}
	//����У�
	for (int col = 0; col < Max_Col; ++col){
		if (chess_board[0][col] == chess_board[1][col]
			&& chess_board[0][col] == chess_board[2][col])
			return chess_board[0][col];
	}
	//���Խ���
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
	printf("���������壡\n");
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
	//1������3*3���̣�
	Make();
	char winner = ' ';
	while (1){
		system("cls");
		//2����ӡ���̣�
		Print();
		//3��������壻
		Player();
		//4��������Ϸ�Ƿ������
		winner=CheckGameover();
		if (winner != ' '){
			break;
		}
		//5���������壻
		Computer();
		//6��������Ϸ�Ƿ������
		winner=CheckGameover();
		if (winner != ' '){
			break;
		}
	}
	system("cls");
	//winner = CheckGameover();
	if (winner == 'x'){
		printf("����������\n");
	}
	else if (winner == 'o'){
		printf("��û�е���������\n");
	}
	else if (winner == 'w'){
		printf("���͵���һ��������\n");
	}
	else{
		printf("ϵͳ����\n");
	}
	
}

int main(){
	while(1){
		int choice = Menu();
		if (choice == 1){
			//��ʼ��Ϸ
			start();
		}
		else if (choice == 0){
			//������Ϸ
			printf("��Ϸ������\n");
			break;
		}
		else{
			printf("������������\n");
		}
	}
	system("pause");
	return 0;
}