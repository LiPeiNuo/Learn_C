//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a = 1, b = 2, c;
//	c = a;
//	a = b;
//	b = c;
//	printf("%d,%d\n" ,a,b);
//	system("pause");
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 1, b = 2;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d\n", a, b);
	system("pause");
		return 0;
}



#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf_s("%d%d%d", &a, &b, &c);
	if (a > b&&a > c)
	{
		if (b > c)
		{
			printf("%d%d%d\n", a, b, c);
		}
		else if (c > b)
		{
			printf("%d%d%d\n", a, c, b);
		}
	}
    if (b > a&&b > c)
	{
		if (a > c)
		{
			printf("%d%d%d\n", b, a, c);
		}
		else if (c > a)
		{
			printf("%d%d%d\n", b, c, a);
		}
	}
	if (c > b&&c > a)
	{
		if (b > a)
		{
			printf("%d%d%d\n", c, b, a);
		}
		else if (a > b)
		{
			printf("%d%d%d", c, a, b);
		}
	}
	system("pause");
}




#define _CRT_RECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int max = 0;
	printf("请输入十个数字");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
		max = arr[0];
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
		printf("%d\n", max);
	system("pause");
	return 0;
}


#define _CRT_RECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	int m = 0;
	int r = 0;
	printf("输入n,m");
	scanf_s("%d %d", &n, &m);
	while (m!=0)
	{
		r = n%m;
		n = m;
		m = r;
	}
	printf("最大公因数为%d\n",n );
	system("pause");
	return 0;
}