//1、使用一个二维数组来表示地图
//2地图的每个元素取值 翻来用一个数字来表示 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10


void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			show_map[row][col] ='*';
		}
	}

	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			mine_map[row][col] =0;
		}
	}

	int count = MINE_COUNT;
	while (count>0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == 1){
			continue;
		}
		mine_map[row][col] = 1;
		--count;
	}
}


void PrintMap(char map[MAX_ROW][MAX_COL]){
	printf("  |");
	for (int col = 0; col < MAX_COL; ++col){
		printf("%d ", col);
	}
	printf("\n");
	printf("---------------------\n");
	for (int row = 0; row < MAX_ROW; ++row){
		printf("%d |", row);
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ",map[row][col]);
		}
		printf("\n");
	}
}

//判定当前位置周围有几个雷，并更新对应的地图
void UpdateMap(char mine_map[MAX_ROW][MAX_COL], char show_map[MAX_ROW][MAX_COL], int row, int col){
	//1、周围八个有几个雷
	//左上
	int mine_count = 0;
	if (row - 1>= 0 && col - 1>= 0 &&mine_map[row-1][col-1]=='1'){
		++mine_count;
	}
	//正上
	if (row - 1 >= 0 && mine_map[row - 1][col] == '1'){
		++mine_count;
	}
	//右上
	if (row - 1 >= 0 && col + 1 < MAX_COL&& mine_map[row - 1][col + 1] == '1'){
		++mine_count;
	}
	//左旁
	if (col - 1 >= 0 && mine_map[row][col - 1] == '1'){
		++mine_count;
	}
	//右旁
	if (col + 1 < MAX_COL && mine_map[row][col + 1] == '1'){
		++mine_count;
	}
	//正下
	if (row + 1 < MAX_ROW && mine_map[row + 1][col] == '1'){
		++mine_count;
	}
	//左下
	if (row + 1 < MAX_ROW && col - 1 >= 0 && mine_map[row + 1][col - 1]){
		++mine_count;
	}
	//右下
	if (row + 1 < MAX_ROW&&col + 1 < MAX_COL&&mine_map[row + 1][col + 1] == '1'){
		++mine_count;
	}
	//2、把这个数字更新贷show_map中
	//字符本质上也是用数字来表示的（ASCII码表）  把数字转为字符
	show_map[row][col] = mine_count + '0';
}

void GetPos(char show_map[MAX_ROW][MAX_COL],int* row,int* col){
	while (1){
		printf("请输入一组坐标：");
		scanf("%d %d",row, col);
		if (*row < 0 ||*row >= MAX_ROW ||*col < 0 ||*col >= MAX_COL){
			printf("你输入的坐标有误，请重新输入！\n");
			continue;
		}
		if (show_map[*row][*col] != '*'){
			printf("你输入的位置已经已经翻来，请重新输入\n");
			continue;
		}
		break;
		UpdateMap(show_map, mine_map, row, col);
	}
}


void Game(){
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	Init(show_map, mine_map);
	int safe_count = 0;
	while (1){
		PrintMap(show_map);
		int row = 0;
		int col = 0;
		GetPos(show_map, &row, &col);
		if (mine_map[row][col] == '1'){
			printf("Game Over\n");
			break;
		}
		++safe_count;
		if (safe_count == MAX_ROW*MAX_COL - MINE_COUNT){
			printf("Game Win\n");
			break;
		}
	}
}

int main(){
	Game();
	system("pause");
	return 0;
}