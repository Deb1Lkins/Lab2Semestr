#define _CRT_SECURE_NO_WARNINGS
#include "Magician.h"
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <algorithm>
#include <iostream> //либо stdlib.h
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
	cout << "кол_во магов в массиве- " << counter << endl;
	cout << "кол-во обычных в массиве- " << size - counter << endl;
	system("pause");
	system("cls");
}
void ChoicePrint(RPGamer** arr, const int& size)
{
	cout << "введите кол-во маны: ";
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
		cout << "нет магов с количеством маны ниже указанного";
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


	cout << "вывод всех объектов: \n";
	PrintArr(arr, size);
	cout << "выводвсех объектов с опред маной" << endl;
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
	cout << "\nпромграмма закончила свою работу\n";
	return 0;
}
/*3) Создать массив объектов, в котором могут быть объекты обоих типов. - max 10
Нужно:
1. Сортировать массив объектов в алфавитном порядке по имени персонажа; массив
распечатать.
2. Вывести информацию обо всех объектах массива;
3. Подсчитать количество объектов каждого класса;
4. Вывести все объекты, у которых текущее значение маны меньше указанного. Если таких
нет, вывести сообщение.*/
