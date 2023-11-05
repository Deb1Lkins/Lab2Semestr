/*Использовать контейнер map <int, SStudData>, ключ – номер зачетки.
1. Ввести данные из текстового файла. Данные подготовлены в виде
строк, соответствующих структуре SStudData.
2. Отсортировать по номеру зачетки и вывести.
3. Вычислить средний балл по каждому студенту.
4. Вывести список всех студентов в виде «Номер по порядку,
Фамилия, Номер_зачетки, Средний_балл» в алфавитном порядке, для
одинаковых фамилий и инициалов – по убыванию среднего балла.
5. Вывести список студентов, средний балл которых принадлежит
заданному диапазону. Порядок – по убыванию среднего балла.
6. Вывести список студентов, которые сдавали заданный предмет.
7. Определить, сколько студентов сдавало каждый предмет.
8. Для каждого предмета определить средний балл, и вывести
предметы и баллы в порядке убывания баллов.
9. Найти всех студентов с максимальной суммой баллов.
10. Найти всех студентов с неудовлетворительными оценками(1,2,3).*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iterator>
#include <Windows.h>
#include <algorithm>
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
struct SMark
{
	string Subject; //предмет
	int Mark; //оценка
};
struct SStudData
{
	string Name; //фамилия, инициалы
	int Number; //номер зачетки
	vector <SMark> marks; //рез-ты сессии
	double average;
};
void Read(ifstream& fin, map<int, SStudData>& mp)
{
	string word;
	SStudData temp_stud;
	SMark arr_marks;
	while (fin >> word)
	{
		temp_stud.Name = word;
		fin >> word;
		temp_stud.Name += " " + word;
		fin >> temp_stud.Number;
		fin >> word;
		arr_marks.Subject = word;
		fin >> arr_marks.Mark;
		temp_stud.marks.push_back(arr_marks);
		fin >> word;
		arr_marks.Subject = word;
		fin >> arr_marks.Mark;;
		temp_stud.marks.push_back(arr_marks);
		fin >> word;
		arr_marks.Subject = word;
		fin >> arr_marks.Mark;
		temp_stud.marks.push_back(arr_marks);
		temp_stud.average = (temp_stud.marks[0].Mark + temp_stud.marks[1].Mark + temp_stud.marks[2].Mark) / 3;
		mp.insert({ temp_stud.Number,temp_stud });
		temp_stud.marks.clear();
	}

}

void PrintMp(map<int, SStudData>& mp);
bool cmp_alp_avg(pair<int, SStudData>& i, pair<int, SStudData>& j);
void PrintVecAvg(vector<pair<int, SStudData>>& arr);

void PrintByAverage(map<int, SStudData>& mp);
void CheckBorders(double& min, double &max);

void PrintBySubject(map<int, SStudData>& mp);

void PrintSubject(map<int, SStudData>& mp);

void Print(map<int,	SStudData>& mp)
{
	int i = 1, j = 0;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr)
	{
		j = 0;
		cout << "Студент номер: " << i++ << endl;
		cout << itr->second.Name << " Номер зачётки: " << itr->first << endl;
		cout << itr->second.marks[j].Subject << '\t' << itr->second.marks[j++].Mark << "\t";
		cout << itr->second.marks[j].Subject << '\t' << itr->second.marks[j++].Mark << "\t";
		cout << itr->second.marks[j].Subject << '\t' << itr->second.marks[j].Mark << "\n";
	}
}

void FindMaxSum(map<int, SStudData> mp)
{
	cout << "Вывод отличников\n";
	bool exist = false;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr)
	{
		if (itr->second.average == 10)
		{
			exist = true;
			cout << itr->second.Name << "\nНомер зачётки: " << itr->first << '\t' << itr->second.average << endl;
		}
	}
	if (!exist)
	{
		cout << "отличников нет\n";
	}
}
void FindUnsatisfied(map<int, SStudData> mp)
{
	cout << "вывод двоичников\n";
	bool flag = false;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr)
	{
		for (int i = 0; i < 3; i++)
		{
			if (itr->second.marks[i].Mark < 4)
			{
				flag = true;
			}
		}
		if (flag)
		{
			cout << itr->second.Name << "\nНомер зачётки: " << itr->first << '\t' << itr->second.average << endl;
			flag = false;
		}
	}
}
int main()
{
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		ifstream fin("Student.txt");
		CheckInputFile(fin);
		map<int, SStudData> mp;
		Read(fin, mp);
	
		PrintMp(mp);
		system("pause");
		system("cls");

		PrintByAverage(mp);
		system("pause");
		system("cls");

		PrintBySubject(mp);
		system("pause");
		system("cls");

		PrintSubject(mp);
		system("pause");
		system("cls");

		FindMaxSum(mp);
		system("pause");
		system("cls");

		FindUnsatisfied(mp);
		system("pause");
		system("cls");
		fin.close();
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	
	return 0;
}

void PrintMp(map<int, SStudData>& mp)
{
	cout << "Сортировка по номеру зачетки и вывод\n";
	vector<pair<int, SStudData>> arr;
	for (auto& it : mp) {
		arr.push_back(it);
	}
	sort(arr.begin(), arr.end(), cmp_alp_avg);
	PrintVecAvg(arr);
}

bool cmp_alp_avg(pair<int, SStudData>& i, pair<int, SStudData>& j)
{
	transform(i.second.Name.begin(), i.second.Name.end(), i.second.Name.begin(), tolower);
	transform(j.second.Name.begin(), j.second.Name.end(), j.second.Name.begin(), tolower);
	if (i.second.Name != j.second.Name)
	{
		return i.second.Name < j.second.Name;
	}
	return i.second.average < j.second.average;
}

void PrintVecAvg(vector<pair<int, SStudData>>& arr)
{
	int i = 1, j;
	for (auto itr = arr.begin(); itr != arr.end(); itr++)
	{
		j = 0;
		cout << "Студент номер: " << i++ << endl;
		cout << itr->second.Name << " Номер зачётки: " << itr->first << endl;
		cout << "Средний балл: " << itr->second.average << "\n";
	}
}

void PrintByAverage(map<int, SStudData>& mp)
{
	cout << "Вывод всех студентов и сортировка по баллам\n";
	double min, max;
	cout << "введите нижний предел баллов:\n";
	cin >> min;
	cout << "введите верхний предел баллов:\n";
	cin >> max;
	CheckBorders(min, max);
	vector<pair<int, SStudData>> arr;
	for (auto& it : mp) 
	{
		if (it.second.average >= min && it.second.average <= max)
		{
			arr.push_back(it);
			continue;
		}
	}
	if (arr.size() == 0)
	{
		cout << "нет студентов с таким средним баллом\n";
	}
	else
	{
		sort(arr.begin(), arr.end(), cmp_alp_avg);
		PrintVecAvg(arr);
	}
}

void CheckBorders(double& min, double& max)
{
	if (min < 0 || max < 0)
	{
		throw"не верный диапазон";
	}
	if (min > max)
	{
		swap(min, max);
	}
}

void PrintBySubject(map<int, SStudData>& mp)
{
	cout << "Вывод студентов здававших определенный предмет\n";
	cout << "введите предмет:\n";
	cin.ignore();
	string temp;
	getline(cin, temp);
	int i = 1;
	transform(temp.begin(), temp.end(), temp.begin(), tolower);
	bool exist = false;
	for (auto& it : mp)
	{
		if (it.second.marks[0].Subject == temp || it.second.marks[1].Subject == temp || it.second.marks[2].Subject == temp)
		{
			cout << "Студент номер: " << i++ << endl;
			cout << it.second.Name << " Номер зачётки: " << it.first << endl;
			exist = true;
			continue;
		}
	}
	if (!exist)
	{
		cout << "никто не сдавал такой предмет\n";
	}
}

void PrintSubject(map<int, SStudData>& mp)
{
	cout << "Отчет по каждому предмету\n";
	string sub1 = "программирование";
	string sub2 = "алгебра";
	string sub3 = "физо";
	int s1 = 0, s2 = 0, s3 = 0;
	int avg1 = 0, avg2 = 0, avg3 = 0;
	for (auto& it : mp)
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (it.second.marks[i].Subject == sub1)
			{
				s1++;
				avg1 += it.second.marks[i].Mark;
				continue;
			}
			if (it.second.marks[i].Subject == sub2)
			{
				s2++;
				avg2 += it.second.marks[i].Mark;
				continue;
			}
			if (it.second.marks[i].Subject == sub3)
			{
				s3++;
				avg3 += it.second.marks[i].Mark;
				continue;
			}
		}
	}
	cout << "Предмет Программирование сдавало: " << s1 << endl;
	if (s1 != 0)
	{
		cout << "Среднйи балл по предмету: " << avg1 / s1 << endl;
	}
	cout << "Предмет Алгебра сдавало: " << s2 << endl;
	if (s2 != 0)
	{
		cout << "Среднйи балл по предмету: " << avg2 / s2 << endl;
	}
	cout << "Предмет Физо сдавало: " << s3 << endl;
	if (s3 != 0)
	{
		cout << "Среднйи балл по предмету: " << avg3 / s3 << endl;
	}
}

