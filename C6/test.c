//����һ������1234���ֱ��ӡ1 2 3 4 
#include<stdio.h>
#include<stdlib.h>
void PrintNum(unsigned int num){
if (num > 9){
		PrintNum(num / 10);
	}
	printf("%d  ", num % 10);
}
int main(){
	PrintNum(1234);
	system("pause");
	return 0;
}


//��n�Ľ׳�
////�ǵݹ�
#include<stdio.h>
#include<stdlib.h>
int Factor(int n){
	int result=1;
	for (int i = 1; i <= n; i++){
		result = result*i;
	}
	return result;
}
int main(){
	printf("%d\n", Factor(5));
	system("pause");
	return 0;
}

////�ݹ���n�Ľ׳�
#include<stdio.h>
#include<stdlib.h>
int Factor(int n){
	if (n==0||n==1){
		return 1;
	}
	return n*Factor(n - 1);
}
int main(){
	printf("%d\n", Factor(4));
	system("pause");
	return 0;
}


//��쳲��������ĵ�n��
#include<stdio.h>
#include<stdlib.h>
int Fib(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}
int main(){

		printf("%d\n", Fib(200));
		system("pause");
		return 0;
}



#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fib(int n){
	int a = 1;
	int b = 1;
	int c ;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main(){
	int a ;
	int ret = 0;
	printf("��ѯ��n��쳲�������\n");
	scanf("%d", &a);
	ret = fib(a);
	printf("%d", ret);
	system("pause");
	return 0;
}



////�ǵݹ�
#include<stdio.h>
#include<stdlib.h>
int Strlen(char str[]){
	int len = 0;
	while (str[len] != '\0'){
		len += 1;
	}
	return len;
}
int main(){
	int len =Strlen("hehe");
	printf("%d\n", len);
	system("pause");
	return 0;
}

////�ݹ�
#include<stdio.h>
#include<stdlib.h>

int Strlen(char str[]){
	if (str[0] == '\0'){
		return 0;
	}
	return 1 + Strlen(str + 1);
}

int main(){
	char str[] = "hehe";
	printf("%d\n", Strlen(str));
	system("pause");
	return 0;
}

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n)
{
	if (n)
	{
		return n % 10 + DigitSum(n / 10);
	}
	return 0;
}

int main()
{
	printf("%d\n", DigitSum(1792));
	system("pause");
	return 0;
}




//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
#include<stdio.h>
#include<stdlib.h>
int mystrlen(char *str)
{
	if (*str == 0)
	{
		return 0;
	}
	return 1 + mystrlen(str + 1);
}

void reverse_string(char * str)
{
	int len = mystrlen(str);
	char tmp;
	if (*str)
	{
		tmp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = 0;
		reverse_string(str + 1);
		str[len - 1] = tmp;
	}
}

int main()
{
	char a[] = "hehe";
	reverse_string(a);
	puts(a);
	system("pause");
	return 0;
}



//��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
#include<stdio.h>
#include<stdlib.h>
int pow(int n, int k)
{
	if (k <= 1){
		return n;
	}
	return n*pow(n, k - 1);
}
int main()
{
	printf("%d\n", pow(3, 3));
	system("pause");
	return 0;
}