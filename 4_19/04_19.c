#include<stdio.h>
#include<stdlib.h>
int main()
{
	int row = 1;
	int col = 1;
	for (row = 1; row <= 9; ++row)
	{
		for (col = 1; col <= row; ++col)
		{
			printf("%d * %d = %d  ", row, col, row*col);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year;
	for (year = 1000; year <= 2000; ++year)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			printf("%d ", year);
		}
	}
	system("pause");
	return 0;
}



//
//#include <stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int year;
//	for (year = 1000; year <= 2000; ++year)
//	{
//		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		{
//			printf("%d ", year);
//		}
//	}
//	system("pause");
//	return 0;
//}








#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i;
	int j;
	for (i = 101; i <= 200; ++i)
	{
		for (j=2; i < j; ++j)
		{
			if (i%j == 0)
				break;
		}
		if (i==j)
			printf("%d", i);
	}
	system("pause");
	return 0;
}