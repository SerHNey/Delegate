#pragma once
#include <stdio.h>
#include <malloc.h>

typedef int (*funcsize)(int, int);  // ������ ���������� �� ������� , ��� ����� ��� ������
typedef funcsize* delegate;  // ��������� �� ������� , ��� ����� ��� ������

typedef struct FuncArray // �������
{
	int count;
	delegate d;
} Funcarray; // ���������������


int multp(int, int);
int razn(int, int);
delegate InitFuncArray();
void AddFunc(Funcarray*, funcsize);
void DelegateDelFunc(Funcarray*, funcsize);
void PrintAllDelegate(Funcarray amount, int a, int b);

