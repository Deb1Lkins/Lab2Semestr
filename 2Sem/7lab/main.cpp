#define _CRT_SECURE_NO_WARNINGS
/*4.9. Разработать абстрактный базовый класс для работы с односвязным кольцевым списком. 
Работа с элементами конкретного типа реализуется в производном классе за счет использования механизма 
виртуальных функций. Написать тестовую программу.*/
#include <Windows.h>
#include "List.h"
#include"RingListInt.h"
#include"RingListDouble.h"
#include"RingListChar.h"
void SetIntL(List** arr);
void SetDoubleL(List** arr);
void SetCharL(List** arr);
void PrintIntL(List** arr);
void PrintDoubleL(List** arr);
void PrintCharL(List** arr);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int Size = 3;
	char* str = new char[Size];
	List** arr = new List * [Size];
	arr[0] = new RingListInt;
	arr[1] = new RingListDouble;
	arr[2] = new RingListChar;
	SetIntL(arr);
	SetDoubleL(arr);
	SetCharL(arr);
	system("cls");
	PrintIntL(arr);
	PrintDoubleL(arr);
	PrintCharL(arr);

	return 0;
}

void SetIntL(List** arr)
{
	RingListInt* ptr;
	int size;
	system("cls");
	cout << "введите размер листа int:\n";
	cin >> size;
	int num;
	ptr = dynamic_cast<RingListInt*>(arr[0]);
	for (size_t i = 0; i < size; i++)
	{
		cout << "введите элемент " << i << ":\n";
		cin >> num;
		ptr->push(num);
	}
}

void SetDoubleL(List** arr)
{
	RingListDouble* ptr;
	int size;
	system("cls");
	cout << "введите размер double:\n";
	cin >> size;
	double num;
	ptr = dynamic_cast<RingListDouble*>(arr[1]);
	for (size_t i = 0; i < size; i++)
	{
		cout << "введите элемент " << i << ":\n";
		cin >> num;
		ptr->push(num);
	}
}

void SetCharL(List** arr)
{
	RingListChar* ptr;
	int size;
	system("cls");
	cout << "введите размер листа char*:\n";
	cin >> size;
	const int Max = 10;
	char* str = new char[Max];
	ptr = dynamic_cast<RingListChar*>(arr[2]);
	cin.getline(str, Max);
	for (size_t i = 0; i < size; i++)
	{
		cout << "введите элемент " << i << ":\n";
		cin.getline(str, Max);
		ptr->push(str);
	}
	delete[] str;
}

void PrintIntL(List** arr)
{
	RingListInt* ptr;
	cout << "список целочисленных:\n";
	ptr = dynamic_cast<RingListInt*>(arr[0]);
	ptr->Print();
}

void PrintDoubleL(List** arr)
{
	RingListDouble* ptr;
	cout << "список числе с плавающей точкой:\n";
	ptr = dynamic_cast<RingListDouble*>(arr[1]);
	ptr->Print();
}

void PrintCharL(List** arr)
{
	RingListChar* ptr;
	cout << "список строк:\n";
	ptr = dynamic_cast<RingListChar*>(arr[2]);
	ptr->Print();
}
