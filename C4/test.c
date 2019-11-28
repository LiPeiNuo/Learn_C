#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define NAME_MAX_SIZE 1024
#define PHONE_MAX_SIZE 100
#define SEX_MAX_SIZE 100
#define AGE_MAX_SIZE 100
#define ADDRESS_MAX_SIZE 1024

typedef struct PersonInfo
{
	char name[NAME_MAX_SIZE];
	char phone[PHONE_MAX_SIZE];
	char sex[SEX_MAX_SIZE];
	char age[AGE_MAX_SIZE];
	char address[ADDRESS_MAX_SIZE];
}PersonInfo;
typedef struct AddrBook
{
	PersonInfo *persons;
	int size;//当前数组中有效元素的个数
	int capacity;//当前数组的最大容量
}AddrBook;

void Init(AddrBook* addr_book)
{
	assert(addr_book != NULL);
	addr_book->size = 0;
	addr_book->capacity = 100;
	addr_book->persons = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
	for (int i = 0; i <addr_book->capacity; ++i)
	{
		memset(addr_book->persons[i].name, 0, NAME_MAX_SIZE);
		memset(addr_book->persons[i].phone, 0, PHONE_MAX_SIZE);
		memset(addr_book->persons[i].age, 0, AGE_MAX_SIZE);
		memset(addr_book->persons[i].sex, 0, SEX_MAX_SIZE);
		memset(addr_book->persons[i].address, 0, ADDRESS_MAX_SIZE);
	}
}

void Add(AddrBook* addr_book)
{
	assert(addr_book != NULL);
	printf("新增联系人！\n");
	if (addr_book->size >= addr_book->capacity)
	{
		addr_book->capacity += 100;
		addr_book->persons =(PersonInfo*)realloc(addr_book->persons, addr_book->capacity);
	}
	PersonInfo*p = &addr_book->persons[addr_book->size];
	printf("请输入新增联系人的姓名：");
	scanf("%s", p->name);
	printf("请输入新增联系人的电话：");
	scanf("%s", p->phone);
	printf("请输入新增联系人的性别：");
	scanf("%s", p->sex);
	printf("请输入新增联系人的年龄：");
	scanf("%s", p->age);
	printf("请输入新增联系人的地址：");
	scanf("%s", p->address);
	++addr_book->size;
}

void Remove(AddrBook* addr_book)
{
	assert(addr_book != NULL);
	printf("删除通讯录中的元素！\n");

	if (addr_book->size == 0)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入要删除元素的序号：");
	int index = 0;
	scanf("%d", &index);
	if (index < 0 || index >= addr_book->size)
	{
		printf("您输入的有误！[0-%d]\n", addr_book->size);
		return;
	}
	if (index == addr_book->size - 1)
	{
		--addr_book->size;
	}
	else
	{
		PersonInfo* mid = &addr_book->persons[index];
		PersonInfo*last = &addr_book->persons[addr_book->size - 1];
		strcpy(mid->name, last->name);
		strcpy(mid->phone, last->phone);
	}
}

void PrinfAll(AddrBook* addr_book)
{
	assert(addr_book != NULL);
	for (int i = 0; i < addr_book->size; ++i)
	{
		PersonInfo*p = &addr_book->persons[i];
		printf("[%d]姓名：%s  电话：%s  性别：%s  年龄：%s  地址：%s\n", i, p->name, p->phone, p->sex, p->age, p->address);
	}
	printf("当前共有%d条记录！\n", addr_book->size);
	printf("-------------------------\n");
}

void Update(AddrBook* addr_book)
{
	assert(addr_book != NULL);
	printf("更新联系人记录！\n");
	if (addr_book->size == 0)
	{
		printf("当前通讯录为空，无法修改\n");
		return;
	}
	printf("请输入您要修改的联系人的序号：");
	int index = 0;
	scanf("%d", &index);
	if (index < 0 || index >= addr_book->size)
	{
		printf("您的输入有误![0-%d]", addr_book->size);
		return;
	}
	PersonInfo*p = &addr_book->persons[index];
	printf("当前姓名为：%s\n请输入修改之后的姓名(*表示不修改)：", &p->name);
	char name[NAME_MAX_SIZE] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0)
	{
		strcpy(p->name, name);
	}
	printf("当前电话为：%s\n请输入修改之后的电话(*表示不修改)：", &p->phone);
	char phone[PHONE_MAX_SIZE] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0)
	{
		strcpy(p->phone, phone);
	}
	printf("当前性别为：%s\n请输入修改之后的性别(*表示不修改)：", &p->sex);
	char sex[SEX_MAX_SIZE] = { 0 };
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0)
	{
		strcpy(p->sex, sex);
	}printf("当前年龄为：%s\n请输入修改之后的年龄(*表示不修改)：", &p->age);
	char age[AGE_MAX_SIZE] = { 0 };
	scanf("%s", age);
	if (strcmp(age, "*") != 0)
	{
		strcpy(p->age, age);
	}printf("当前地址为：%s\n请输入修改之后的地址(*表示不修改)：", &p->address);
	char address[ADDRESS_MAX_SIZE] = { 0 };
	scanf("%s", address);
	if (strcmp(address, "*") != 0)
	{
		strcpy(p->address, address);
	}
}

int Menu()
{
	printf("-------------------------\n");
	printf("   欢迎使用通讯录程序!\n");
	printf("   1.显示所有联系人信息\n");
	printf("   2.新增联系人信息\n");
	printf("   3.修改联系人信息\n");
	printf("   4.删除联系人信息\n");
	printf("   0.退出通讯录程序\n");
	printf("-------------------------\n");
	printf("请输入您的选择:");
	int chioce = 0;
	scanf("%d", &chioce);
	return chioce;
}

AddrBook addr_book;
typedef void(*Func)(AddrBook*);
int main()
{
	Init(&addr_book);
	Func func_table[] =
	{
		PrinfAll,
		Add,
		Update,
		Remove,
	};
	while (1)
	{
		int chioce = Menu();
		if (chioce<0 || chioce>4)
		{
			printf("您的输入有误！请重新输入！\n");
			continue;
		}
		if (chioce == 0)
		{
			printf("godbye!\n");
			break;
		}
		func_table[chioce - 1](&addr_book);
	}
	system("pause");
	return 0;
}



//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//int main()
//{
//	int arr[10] = { 0 };//连续的    栈
//	int *p = (int*)malloc(sizeof(int)* 10);//连续的    堆
//	assert(p != NULL);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	free(p);//释放所指动态内存，避免内存泄漏
//	p = NULL;//避免野指针
//	system("pause");
//	return 0;
//}
//
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
////void* calloc(size_t num,size_t size)
//int main()
//{
//	int *p = calloc(10, sizeof(int));
//	assert(p != NULL);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	free(p);
//	p = NULL;
//	system("pause");
//	return 0;
//}
//
//
