

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<Windows.h>
//int main(){
//	char str1[] = "welcome to bit !";
//	char str2[] = "################";
//	int left = 0;
//	int right = strlen(str1) - 1;
//	while (left <= right){
//		printf("%s\n", str2);
//		str2[left] = str1[left];
//		str2[right] = str1[right];
//		left += 1;
//		right -= 1;
//		Sleep(200);
//	}
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//	char password[] = "123456";
//	int i = 0;
//	for (; i < 3; i++){
//	printf("���������룺");
//	char input[10] = { 0 };
//	scanf("%s", input);
//	if (strcmp(password, input) == 0){
//		printf("��½�ɹ���\n");
//		break;
//	}
//	else {
//		printf("��½ʧ�ܣ������ԣ�\n");
//	}
//}
//	if (i ==3){
//		printf("���Ѿ���½����\n");
//	}
//	system("pause");
//	return 0;
//}

//
//
//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//	int mun = 4;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	for (int i = 0; i < 10; i++){
//		if (arr[i] == mun){
//			printf("�ҵ�����λ����%d\n", i);
//			break;
//		}
//		if (i==10){
//			printf("û�ҵ���");
//		}
//	}
//	system("pause");
//	return 0;
//
//}





#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 3
#define MAX_COL 3

void Init(char board[MAX_ROW][MAX_COL]){

	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			board[row][col] = ' ';
	    }
    }
	srand(time(0));
}


void Print(char board[MAX_ROW][MAX_COL]){
	printf(" ---|---|---\n");
	for (int row = 0; row < MAX_ROW; ++row){
			printf("| %c | %c | %c |\n",
				board[row][0], board[row][1], board[row][2]);
			printf(" ---|---|---\n");
	}
}


void PlayerMove(char board[MAX_ROW][MAX_COL]){
	while (1){
		printf("��������Ҫ����λ�õ�����(row col):\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row,&col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("������������������������룡\n");
			continue;
		}
		if (board[row][col] != ' '){
			printf("��λ���Ѿ������ˣ����������룡\n");
			continue;
		}
		board[row][col] = 'x';
		break;
	}
}


int IsFull(char board[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			if (board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}


char IsWin(char board[MAX_ROW][MAX_COL]){

	for (int row = 0; row < MAX_ROW; ++row){
		if ( board[row][0] == board[row][1]
			&& board[row][0]== board[row][2] && board[row][0] != ' '){
			return board[row][0];
		}
	}

	for (int col = 0; col < MAX_COL; ++col){
		if (board[0][col] == board[1][col] &&
			board[0][col] == board[2][col] && board[0][col] != ' ')
			return board[0][col];
 	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2]
		&&board[0][0]!='0'){
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0]
		&& board[0][2] != ' '){
		return board[0][2];
	}
	if (IsFull(board)){
		return'=';
	}
	return ' ';
}


void ComputerMove(char board[MAX_ROW][MAX_COL]){//��������
	
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (board[row][col] != ' '){
			continue;
		}
		board[row][col] = 'o';
		break;
	}
}

int main(){
	char chess_board[MAX_ROW][MAX_COL];
	Init(chess_board);//���г�ʼ��
	char result = IsWin(chess_board);
	while (1){
		Print(chess_board);//��ӡ����
		PlayerMove(chess_board);//�������
		if (result != ' '){
			break;
		}
		ComputerMove(chess_board);
		result = IsWin(chess_board);
		if (result != ' '){
			break;
		}
	}

		if (result == 'x'){
			printf("��Ӯ�ˣ�\n");
		}
		else if (result == 'o'){
			printf("����ˣ�\n");
		}
		else{
			printf("�㻹����ˣ������Զ��²�����\n");
		}
		system("pause");
		return 0;
	}
