#pragma once
#include <stdio.h>
#include <malloc.h>

typedef int (*funcsize)(int, int);  // Массив указателей на функцию , как новый тип данных
typedef funcsize* delegate;  // Указатель на функцию , как новый тип данных

typedef struct FuncArray // Делегат
{
	int count;
	delegate d;
} Funcarray; // переопределение


int multp(int, int);
int razn(int, int);
delegate InitFuncArray();
void AddFunc(Funcarray*, funcsize);
void DelegateDelFunc(Funcarray*, funcsize);
void PrintAllDelegate(Funcarray amount, int a, int b);

