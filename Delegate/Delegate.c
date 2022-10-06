#include "Source.c"
typedef struct FuncArray* funca;

main() {
	system("chcp 1251>nul");
	Funcarray funcarray = { 0,InitFuncArray() }; // Инициализация делегата

	AddFunc(&funcarray, razn); // Добавление функций в делегат
	AddFunc(&funcarray, multp);
	AddFunc(&funcarray, multp);

	PrintAllDelegate(funcarray, 5, 3); // Вывод всех существующих функций в делегате

	DelegateDelFunc(&funcarray, multp); // Удаление функций из делегата

	PrintAllDelegate(funcarray, 5, 3);

}

int razn(int a, int b) {
	printf("Cумма равна = ");
	return a - b;
}

int multp(int a, int b) {
	printf("Умножение равно = ");
	return a * b;
}

delegate InitFuncArray() {  // Инициализация делегата 
	delegate d = calloc(1, sizeof(funcsize)); // Выделение памяти под 1 функцию
	return d;
}

void AddFunc(Funcarray* amount, funcsize func) {  // Добавление новой функции в делегат
	amount->count++; // Увеличение размера делегата под ещё одну функцию
	amount->d = realloc(amount->d, (amount->count + 1) * sizeof(funcsize));
	amount->d[amount->count - 1] = func;
}

void DelegateDelFunc(Funcarray* amount, funcsize func) {  // Удаление повторяющихся/не повторяющихся функций из делегата
	int n = amount->count;
	for (int i = 0; i < n; i++)
	{
		if (amount->d[i] == func) {
			amount->d[i] = NULL;
			amount->count--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (amount->d[i] == NULL)
			amount->d[i] = amount->d[i + 1];
	}
	amount->d = realloc(amount->d, (amount->count) * sizeof(funcsize));
}

void PrintAllDelegate(Funcarray amount, int a, int b) {  // Вывод всех добавленых функций в делегат
	for (int i = 0; i < amount.count; i++)
	{
		printf("%d ", amount.d[i](a, b));
	}
	printf("\n");
}

