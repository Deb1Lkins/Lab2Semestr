/*
№клумбы;геометрическая форма клумбы;перечень цветов, растущих на клумбе
Данные разделены точкой с запятой, цветы – запятой, все остальные символы являются частью данных. В конце строки разделителей нет. 
Все строки различны и не отсортированы. Данные корректны. 
Для строк использовать string. Обязательна проверка по существование файла и пустоту. 
Для хранения данных использовать структуру.
Тестовые данные должны учитывать все случаи (оценивается полнота тестов). В частях 2 и 3 предусмотреть отсутствие данных. 
Результаты вывести на консоль в удобном для чтения, информативном виде.
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
void CheckInputFile(ifstream& fin)
{
	if (fin.fail())
	{
		throw "file is not exist";
	}
	if (!fin.is_open())
	{
		throw "file opening error!";
	}
	if (fin.peek() == EOF)
	{
		throw "file is empty!";
	}
}
struct FlowerBedS
{
	int num;
	string shape;
	list<string> flowers;
	friend ostream& operator<<(ostream& out, const FlowerBedS& other)
	{
		out << "Клумба №: " << other.num << '\t'
			<< "Форма: " << other.shape << '\t'
			<< "Цветы: ";
		for (auto it = other.flowers.begin(); it != other.flowers.end(); it++)
		{
			out << *it << ", ";
		}
		out << endl;
		return out;
	}
};
void ReadArr(vector<FlowerBedS>& arr, ifstream& fin);
void PrintSelected(set<string>& flowers, vector<FlowerBedS>& arr);
void FindFullFlower(vector<FlowerBedS>& arr, set<string> flowers);
void ChangeFlower(vector<FlowerBedS>& arr);
void CountDifferent(vector<FlowerBedS>& arr);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin("data.txt");
	CheckInputFile(fin);
	vector<FlowerBedS>arr;
	ReadArr(arr,fin);
	sort(arr.begin(), arr.end(), [](FlowerBedS i, FlowerBedS j){
	transform(i.shape.begin(), i.shape.end(), i.shape.begin(), toupper);
	transform(j.shape.begin(), j.shape.end(), j.shape.begin(), toupper);
	if (i.shape != j.shape) { return i.shape > j.shape; }
	return i.num < j.num; });


	//set
	set<string> flowers;
	PrintSelected(flowers, arr);
	ChangeFlower(arr);

	return 0;
}

void ReadArr(vector<FlowerBedS>& arr, ifstream& fin)
{
	FlowerBedS temp;
	string str, flower;
	while (getline(fin,str))
	{
		if (str.empty())
		{
			continue;
		}
		istringstream iss(str);
		iss >> temp.num;
		getline(iss, temp.shape, ';');
		getline(iss, temp.shape, ';');
		while (getline(iss, flower, ',') && !flower.empty())
		{
			temp.flowers.push_back(flower);
		}
        arr.push_back(temp);
		temp.flowers.clear();
	}
}

void PrintSelected(set<string>& flowers, vector<FlowerBedS>& arr)
{
	string str;
	cout << "Задание: нахожднение клумбы на которой нет заданного цветка\n";
	cout << "введите нужный цветок: ";
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	bool exist = false;
	cout << " Клумбы на которых нет данного цветка:\n";
	for (auto it : arr)
	{
		for (auto flow = it.flowers.begin(); flow != it.flowers.end(); flow++)
		{
			flowers.insert(*flow);
			if (*flow == str)
			{
				exist = true;
			}
		}
		if (!exist)
		{
			cout << it;
		}
		exist = false;
	}
	system("pause");
	system("cls");
	cout << "Задание: Все возможные цветы на клумбах:\n";
	for (auto it = flowers.begin(); it != flowers.end(); it++)
	{
		cout << *it << " ";
	}
	system("pause");
	system("cls");
	cout << "Задание: цветок который есть на всех клумбах:\n";
	FindFullFlower(arr, flowers);
	system("pause");
	system("cls");
}

void FindFullFlower(vector<FlowerBedS>& arr, set<string> flowers)
{
	bool exist = false;
	int counter = 0;
	for (auto s : flowers)
	{
		for (auto fl : arr)
		{
			for (auto flower : fl.flowers)
			{
				if (s == flower)
				{
					counter++;
				}
			}
		}
		if (counter == arr.size())
		{
			exist = true;
			cout << s << endl;
		}
		counter = 0;
	}
	if (!exist)
	{
		cout << "такого цветка нет\n";
	}
}

void ChangeFlower(vector<FlowerBedS>& arr)
{
	cout << "введите цветок который хотите заменить\n";
	string str;
	getline(cin, str);
	cout << "введите новый цветок\n";
	string flow_new;
	getline(cin, flow_new); 
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		for (auto flow = it->flowers.begin(); flow != it->flowers.end(); flow++)
		{
			if (*flow == str)
			{
				*flow = flow_new;
			}
		}
	}
}

void CountDifferent(vector<FlowerBedS>& arr)
{
	size_t size;
	set<string> temp;
	bool flag = true;
	cout << "Введите количество различных цветов: ";
	cin >> size;
	for (auto fl : arr)
	{
		for (auto flower : fl.flowers)
		{
			temp.insert(flower);
		}
		if (temp.size() >= size)
		{
			cout << fl;
			flag = false;
		}
		temp.clear();
	}
	if (flag)
	{
		cout << "Таких различных цветков нет ни на одной клумбе!\n";
	}
}
