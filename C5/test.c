//1��ʹ��һ����ά��������ʾ��ͼ
//2��ͼ��ÿ��Ԫ��ȡֵ ������һ����������ʾ 
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

//�ж���ǰλ����Χ�м����ף������¶�Ӧ�ĵ�ͼ
void UpdateMap(char mine_map[MAX_ROW][MAX_COL], char show_map[MAX_ROW][MAX_COL], int row, int col){
	//1����Χ�˸��м�����
	//����
	int mine_count = 0;
	if (row - 1>= 0 && col - 1>= 0 &&mine_map[row-1][col-1]=='1'){
		++mine_count;
	}
	//����
	if (row - 1 >= 0 && mine_map[row - 1][col] == '1'){
		++mine_count;
	}
	//����
	if (row - 1 >= 0 && col + 1 < MAX_COL&& mine_map[row - 1][col + 1] == '1'){
		++mine_count;
	}
	//����
	if (col - 1 >= 0 && mine_map[row][col - 1] == '1'){
		++mine_count;
	}
	//����
	if (col + 1 < MAX_COL && mine_map[row][col + 1] == '1'){
		++mine_count;
	}
	//����
	if (row + 1 < MAX_ROW && mine_map[row + 1][col] == '1'){
		++mine_count;
	}
	//����
	if (row + 1 < MAX_ROW && col - 1 >= 0 && mine_map[row + 1][col - 1]){
		++mine_count;
	}
	//����
	if (row + 1 < MAX_ROW&&col + 1 < MAX_COL&&mine_map[row + 1][col + 1] == '1'){
		++mine_count;
	}
	//2����������ָ��´�show_map��
	//�ַ�������Ҳ������������ʾ�ģ�ASCII���  ������תΪ�ַ�
	show_map[row][col] = mine_count + '0';
}

void GetPos(char show_map[MAX_ROW][MAX_COL],int* row,int* col){
	while (1){
		printf("������һ�����꣺");
		scanf("%d %d",row, col);
		if (*row < 0 ||*row >= MAX_ROW ||*col < 0 ||*col >= MAX_COL){
			printf("������������������������룡\n");
			continue;
		}
		if (show_map[*row][*col] != '*'){
			printf("�������λ���Ѿ��Ѿ�����������������\n");
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