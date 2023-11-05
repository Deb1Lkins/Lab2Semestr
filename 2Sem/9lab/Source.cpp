/*������������ ��������� map <int, SStudData>, ���� � ����� �������.
1. ������ ������ �� ���������� �����. ������ ������������ � ����
�����, ��������������� ��������� SStudData.
2. ������������� �� ������ ������� � �������.
3. ��������� ������� ���� �� ������� ��������.
4. ������� ������ ���� ��������� � ���� ������ �� �������,
�������, �����_�������, �������_���� � ���������� �������, ���
���������� ������� � ��������� � �� �������� �������� �����.
5. ������� ������ ���������, ������� ���� ������� �����������
��������� ���������. ������� � �� �������� �������� �����.
6. ������� ������ ���������, ������� ������� �������� �������.
7. ����������, ������� ��������� ������� ������ �������.
8. ��� ������� �������� ���������� ������� ����, � �������
�������� � ����� � ������� �������� ������.
9. ����� ���� ��������� � ������������ ������ ������.
10. ����� ���� ��������� � ��������������������� ��������(1,2,3).*/
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
	string Subject; //�������
	int Mark; //������
};
struct SStudData
{
	string Name; //�������, ��������
	int Number; //����� �������
	vector <SMark> marks; //���-�� ������
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
		cout << "������� �����: " << i++ << endl;
		cout << itr->second.Name << " ����� �������: " << itr->first << endl;
		cout << itr->second.marks[j].Subject << '\t' << itr->second.marks[j++].Mark << "\t";
		cout << itr->second.marks[j].Subject << '\t' << itr->second.marks[j++].Mark << "\t";
		cout << itr->second.marks[j].Subject << '\t' << itr->second.marks[j].Mark << "\n";
	}
}

void FindMaxSum(map<int, SStudData> mp)
{
	cout << "����� ����������\n";
	bool exist = false;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr)
	{
		if (itr->second.average == 10)
		{
			exist = true;
			cout << itr->second.Name << "\n����� �������: " << itr->first << '\t' << itr->second.average << endl;
		}
	}
	if (!exist)
	{
		cout << "���������� ���\n";
	}
}
void FindUnsatisfied(map<int, SStudData> mp)
{
	cout << "����� ����������\n";
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
			cout << itr->second.Name << "\n����� �������: " << itr->first << '\t' << itr->second.average << endl;
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
	cout << "���������� �� ������ ������� � �����\n";
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
		cout << "������� �����: " << i++ << endl;
		cout << itr->second.Name << " ����� �������: " << itr->first << endl;
		cout << "������� ����: " << itr->second.average << "\n";
	}
}

void PrintByAverage(map<int, SStudData>& mp)
{
	cout << "����� ���� ��������� � ���������� �� ������\n";
	double min, max;
	cout << "������� ������ ������ ������:\n";
	cin >> min;
	cout << "������� ������� ������ ������:\n";
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
		cout << "��� ��������� � ����� ������� ������\n";
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
		throw"�� ������ ��������";
	}
	if (min > max)
	{
		swap(min, max);
	}
}

void PrintBySubject(map<int, SStudData>& mp)
{
	cout << "����� ��������� ��������� ������������ �������\n";
	cout << "������� �������:\n";
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
			cout << "������� �����: " << i++ << endl;
			cout << it.second.Name << " ����� �������: " << it.first << endl;
			exist = true;
			continue;
		}
	}
	if (!exist)
	{
		cout << "����� �� ������ ����� �������\n";
	}
}

void PrintSubject(map<int, SStudData>& mp)
{
	cout << "����� �� ������� ��������\n";
	string sub1 = "����������������";
	string sub2 = "�������";
	string sub3 = "����";
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
	cout << "������� ���������������� �������: " << s1 << endl;
	if (s1 != 0)
	{
		cout << "������� ���� �� ��������: " << avg1 / s1 << endl;
	}
	cout << "������� ������� �������: " << s2 << endl;
	if (s2 != 0)
	{
		cout << "������� ���� �� ��������: " << avg2 / s2 << endl;
	}
	cout << "������� ���� �������: " << s3 << endl;
	if (s3 != 0)
	{
		cout << "������� ���� �� ��������: " << avg3 / s3 << endl;
	}
}

