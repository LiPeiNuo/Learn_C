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
	int size;//��ǰ��������ЧԪ�صĸ���
	int capacity;//��ǰ������������
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
	printf("������ϵ�ˣ�\n");
	if (addr_book->size >= addr_book->capacity)
	{
		addr_book->capacity += 100;
		addr_book->persons =(PersonInfo*)realloc(addr_book->persons, addr_book->capacity);
	}
	PersonInfo*p = &addr_book->persons[addr_book->size];
	printf("������������ϵ�˵�������");
	scanf("%s", p->name);
	printf("������������ϵ�˵ĵ绰��");
	scanf("%s", p->phone);
	printf("������������ϵ�˵��Ա�");
	scanf("%s", p->sex);
	printf("������������ϵ�˵����䣺");
	scanf("%s", p->age);
	printf("������������ϵ�˵ĵ�ַ��");
	scanf("%s", p->address);
	++addr_book->size;
}

void Remove(AddrBook* addr_book)
{
	assert(addr_book != NULL);
	printf("ɾ��ͨѶ¼�е�Ԫ�أ�\n");

	if (addr_book->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("������Ҫɾ��Ԫ�ص���ţ�");
	int index = 0;
	scanf("%d", &index);
	if (index < 0 || index >= addr_book->size)
	{
		printf("�����������[0-%d]\n", addr_book->size);
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
		printf("[%d]������%s  �绰��%s  �Ա�%s  ���䣺%s  ��ַ��%s\n", i, p->name, p->phone, p->sex, p->age, p->address);
	}
	printf("��ǰ����%d����¼��\n", addr_book->size);
	printf("-------------------------\n");
}

void Update(AddrBook* addr_book)
{
	assert(addr_book != NULL);
	printf("������ϵ�˼�¼��\n");
	if (addr_book->size == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ��޷��޸�\n");
		return;
	}
	printf("��������Ҫ�޸ĵ���ϵ�˵���ţ�");
	int index = 0;
	scanf("%d", &index);
	if (index < 0 || index >= addr_book->size)
	{
		printf("������������![0-%d]", addr_book->size);
		return;
	}
	PersonInfo*p = &addr_book->persons[index];
	printf("��ǰ����Ϊ��%s\n�������޸�֮�������(*��ʾ���޸�)��", &p->name);
	char name[NAME_MAX_SIZE] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0)
	{
		strcpy(p->name, name);
	}
	printf("��ǰ�绰Ϊ��%s\n�������޸�֮��ĵ绰(*��ʾ���޸�)��", &p->phone);
	char phone[PHONE_MAX_SIZE] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0)
	{
		strcpy(p->phone, phone);
	}
	printf("��ǰ�Ա�Ϊ��%s\n�������޸�֮����Ա�(*��ʾ���޸�)��", &p->sex);
	char sex[SEX_MAX_SIZE] = { 0 };
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0)
	{
		strcpy(p->sex, sex);
	}printf("��ǰ����Ϊ��%s\n�������޸�֮�������(*��ʾ���޸�)��", &p->age);
	char age[AGE_MAX_SIZE] = { 0 };
	scanf("%s", age);
	if (strcmp(age, "*") != 0)
	{
		strcpy(p->age, age);
	}printf("��ǰ��ַΪ��%s\n�������޸�֮��ĵ�ַ(*��ʾ���޸�)��", &p->address);
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
	printf("   ��ӭʹ��ͨѶ¼����!\n");
	printf("   1.��ʾ������ϵ����Ϣ\n");
	printf("   2.������ϵ����Ϣ\n");
	printf("   3.�޸���ϵ����Ϣ\n");
	printf("   4.ɾ����ϵ����Ϣ\n");
	printf("   0.�˳�ͨѶ¼����\n");
	printf("-------------------------\n");
	printf("����������ѡ��:");
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
			printf("���������������������룡\n");
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
//	int arr[10] = { 0 };//������    ջ
//	int *p = (int*)malloc(sizeof(int)* 10);//������    ��
//	assert(p != NULL);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	free(p);//�ͷ���ָ��̬�ڴ棬�����ڴ�й©
//	p = NULL;//����Ұָ��
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
