#define _CRT_SECURE_NO_WARNINGS
#include "Magician.h"
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <algorithm>
#include <iostream> //���� stdlib.h
bool compare(const void* i, const void* j)
{
	return _stricmp(((RPGamer*)i)->GetName(), ((RPGamer*)j)->GetName()) < 0;
	
}
void PrintArr(RPGamer** arr, const int& size)
{
	int counter = 0;
	Magician* ptr;
	for (size_t i = 0; i < size; i++)
	{
		ptr = dynamic_cast<Magician*>(arr[i]);
		if (ptr != nullptr)
		{
			cout << *ptr;
			counter++;
		}
		else
		{
			cout << *arr[i];
		}
	}
	cout << "���_�� ����� � �������- " << counter << endl;
	cout << "���-�� ������� � �������- " << size - counter << endl;
	system("pause");
	system("cls");
}
void ChoicePrint(RPGamer** arr, const int& size)
{
	cout << "������� ���-�� ����: ";
	int mana, counter = 0;
	cin >> mana;
	Magician* ptr;
	for (size_t i = 0; i < size; i++)
	{
		ptr = dynamic_cast<Magician*>(arr[i]);
		if (ptr)
		{
			if (ptr->GetMana() < mana)
			{
				cout << *ptr;
				counter++;
			}
			
		}
		else
		{
			continue;
		}
	}
	if (!counter)
	{
		cout << "��� ����� � ����������� ���� ���� ����������";
	}
}
void Run()
{
	const int size = 5;
	char* str = new char[10];

	RPGamer** arr = new RPGamer * [size];
	strcpy(str, "matvey");
	arr[0] = new Magician(str, condition::normaly, species::elf, true, 500, 500, 5);
	strcpy(str, "peta");
	arr[1] = new RPGamer(str, condition::normaly, species::human, true);
	strcpy(str, "peta");
	arr[2] = new Magician(str, condition::dead, species::elf, false, 200, 101, 5);
	strcpy(str, "maks");
	arr[3] = new RPGamer(str, condition::paralyzed, species::dwarf, true);
	strcpy(str, "arsen");
	arr[4] = new Magician(str, condition::dead, species::elf, false, 300, 50, 5);
	sort(arr, arr + size, compare);


	cout << "����� ���� ��������: \n";
	PrintArr(arr, size);
	cout << "��������� �������� � ����� �����" << endl;
	ChoicePrint(arr, size);
	for (size_t i = 0; i < size; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
int main()
{
	system("mode con cols=2000 lines=2000");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Run();
	cout << "\n���������� ��������� ���� ������\n";
	return 0;
}
/*3) ������� ������ ��������, � ������� ����� ���� ������� ����� �����. - max 10
�����:
1. ����������� ������ �������� � ���������� ������� �� ����� ���������; ������
�����������.
2. ������� ���������� ��� ���� �������� �������;
3. ���������� ���������� �������� ������� ������;
4. ������� ��� �������, � ������� ������� �������� ���� ������ ����������. ���� �����
���, ������� ���������.*/
