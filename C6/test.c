//给定一个整数1234，分别打印1 2 3 4 
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


//求n的阶乘
////非递归
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

////递归求n的阶乘
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


//求斐波那契数的第n项
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
	printf("查询第n个斐波那契数\n");
	scanf("%d", &a);
	ret = fib(a);
	printf("%d", ret);
	system("pause");
	return 0;
}



////非递归
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

////递归
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

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
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




//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
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



//编写一个函数实现n^k，使用递归实现
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