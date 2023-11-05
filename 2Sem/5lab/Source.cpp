#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <Windows.h>
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::ios;
using std::swap;
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
void CheckFout(ofstream& fout)
{
	if (!fout.is_open())
	{
		throw"file opening error!";
	}
}
//advantage
struct AdvStud
{
	int card;
	int group;
	char surname[100]; //ф
};
struct Student
{
	int card;
	char surname[100]; //ф
	char name[100]; //и
	char patronymic[100]; //о
	int group;
	int mark_ma;
	int mark_geo;
	int mark_prog;
	int average;
};
int CountStud();
void ChoiceSortGroup(Student* arr, const int& size);
void SortSurname(Student* st, const int& num);
void CompletionStud(Student* arr, const int& size);
void CompletionMarks(Student* arr, const int& size);

void FormBinFile(Student* arr, const int& size);
void FormBinFileWorst(Student* arr, const int& size, AdvStud* worst, const int& numb);
void FormBinFileBest(Student* arr, const int& size, AdvStud* best, const int& numb);
void Print1(ifstream& fin, Student* arr, const int& size);
void Print2(ifstream& fin, Student* arr, const int& size);
void Print3(ifstream& fin, AdvStud* arr, const int& size);

int comp_group(const void* i, const void* j);
int comp_alp(const void* i, const void* j);
int comp_avg(const void* i, const void* j);
int comp_all(const void* i, const void* j);
void PrintInfile1(const int& size, Student* arr);
void PrintInfile2(const int& size,Student* arr);
void PrintInfile3(const int& size, AdvStud* arr);

int CounterWorst(Student* arr, const int& size);
int CounterBest(Student* arr, const int& size);
int CounterGroup(Student* arr, const int& size, const int& group);
void CheckGroup(const int& group);
void FormSpecGroup(Student* arr, const int& size, Student* temp, const int& numb, const int& group);
void Run()
{
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		const int size = CountStud() - 1;
		Student* arr = new Student[size];
		CompletionStud(arr, size);
		CompletionMarks(arr, size);
		char choice;
		cout << "выберите способ сортировки:\n"
			<< "a) своя\n"
			<< "b) qsort\n";
		cin >> choice;
		switch (choice)
		{
		case 'a':
		{
			SortSurname(arr, size);
			ChoiceSortGroup(arr, size);
			break;
		}
		case 'b':
		{
			qsort(arr, size, sizeof(Student), comp_all);
			break;
		}
		default:
			throw"incorrect choice\n";
			break;
		}
		cout << "выберите задание\n"
			<< "a) формирования бинарных файлов на базе текстовых;\n"
			<< "b) подсоединения фамилии студентов к ведомостям оценок с формированием нового бинарного файла;\n"
			<< "c) вычисления среднего балла каждого студента с формированием нового бинарного файла;\n"
			<< "d) формирования списка неуспевающих, состоящего из фамилии, номера группы, номера зачетки;\n"
			<< "e) сортировки списка неуспевающих по группам, каждую группу по фамилиям в алфавитном порядке; \n"
			<< "f) распечатки бинарного файла до сортировки и после;\n"
			<< "g) формирования ведомости оценок для заданной группы, упорядоченной по алфавиту;\n"
			<< "h) формирования ведомости оценок для заданной группы, упорядоченной по убыванию среднего балла;\n"
			<< "i) формирования списка отличников, состоящего из фамилии, номера группы, номера зачетки; \n";
		cin >> choice;
		switch (choice)
		{
		case 'a':
		{
			//надеюсь вы умные и сделаете презентацию
			//код тот же что и в прошлый раз здесь был
			//удачи ;)
			break;
		}
		case 'b':
		{
			/*b) подсоединения фамилии студентов к ведомостям оценок с формированием нового бинарного файла;*/
			cout << "Задание B" << endl;
			PrintInfile1(size, arr);
			FormBinFile(arr, size);
			ifstream fin("out.bin", ios::binary);
			CheckInputFile(fin);
			Print1(fin, arr, size);
			fin.close();
			break;
		}
		case 'c':
		{
			/*c) вычисления среднего балла каждого студента с формированием нового бинарного файла;*/
			cout << "Задание C" << endl;
			PrintInfile2(size, arr);
			FormBinFile(arr, size);
			ifstream fin("out.bin", ios::binary);
			CheckInputFile(fin);
			Print2(fin, arr, size);
			fin.close();
			break;
		}
		case 'd':
		{
			/*d) формирования списка неуспевающих, состоящего из фамилии, номера группы, номера зачетки;*/
			cout << "Задание D" << endl;
			int numb = CounterWorst(arr, size);
			AdvStud* worst = new AdvStud[numb];
			FormBinFileWorst(arr, size, worst, numb);
			PrintInfile3(numb, worst);
			ifstream fin("out.bin", ios::binary);
			CheckInputFile(fin);
			Print3(fin, worst, numb);
			fin.close();
			delete[]worst;
			break;
		}
		case 'e':
		{
			/*e) сортировки списка неуспевающих по группам,
		каждую группу по фамилиям в алфавитном порядке;*/
			cout << "Задание D + sort" << endl;
			qsort(arr, size, sizeof(Student), comp_all);
			int numb = CounterWorst(arr, size);
			AdvStud* worst = new AdvStud[numb];
			FormBinFileWorst(arr, size, worst, numb);
			PrintInfile3(numb, worst);
			ifstream fin("out.bin", ios::binary);
			CheckInputFile(fin);
			Print3(fin, worst, numb);
			fin.close();
			delete[]worst;
			break;
		}
		case 'f':
		{
			/*f) распечатки бинарного файла до сортировки и после (здесь не выводиться до сортировки потому что мы изначально все сортируем)*/
			cout << "Задание B + sort" << endl;
			PrintInfile1(size, arr);
			FormBinFile(arr, size);
			ifstream fin("out.bin", ios::binary);
			CheckInputFile(fin);
			Print1(fin, arr, size);
			fin.close();
			break;
		}
		case 'g':
		{
			/*g) формирования ведомости оценок для заданной группы, упорядоченной по алфавиту*/
			cout << "enter a group:\n";
			int group;
			cin >> group;
			CheckGroup(group);
			int numb = CounterGroup(arr, size, group);
			Student* temp = new Student[numb];
			FormSpecGroup(arr, size, temp, numb, group);
			PrintInfile1(numb, temp);
			qsort(temp, size, sizeof(Student), comp_alp);
			cout << "Задание G" << endl;
			FormBinFile(temp, numb);
			ifstream fin("out.bin", ios::binary);
			CheckInputFile(fin);
			Print1(fin, temp, numb);
			fin.close();
			break;
		}
		case 'h':
		{
			/*h) формирования ведомости оценок для заданной группы, упорядоченной по убыванию среднего балла;*/
			cout << "enter a group:\n";
			int group;
			cin >> group;
			CheckGroup(group);
			int numb = CounterGroup(arr, size, group);
			Student* temp = new Student[numb];
			FormSpecGroup(arr, size, temp, numb, group);
			PrintInfile1(numb, temp);
			qsort(temp, size, sizeof(Student), comp_avg);
			cout << "Задание G" << endl;
			FormBinFile(temp, numb);
			ifstream fin("out.bin", ios::binary);
			CheckInputFile(fin);
			Print1(fin, temp, numb);
			fin.close();
			break;
		}
		case 'i':
		{
			/*i) формирования списка отличников, состоящего из фамилии, номера группы, номера зачетки;*/
			cout << "Задание I" << endl;
			int numb = CounterBest(arr, size);
			AdvStud* best = new AdvStud[numb];
			FormBinFileWorst(arr, size, best, numb);
			PrintInfile3(numb, best);
			ifstream fin("out.bin", ios::binary);
			CheckInputFile(fin);
			Print3(fin, best, numb);
			fin.close();
			delete[]best;
			break;
		}
		default:
			throw"incorrect choice\n";
			break;
		}
		cout << "\ncheck binary files\n";
		cout << "*************************\n";
		cout << "check result.txt";
		delete[]arr;
	}
	catch (const char* msg)
	{
		cout << msg;
	}
}
int main()
{
	Run();
	cout << "\nпрограмма завершила свою работу\n";
	return 0;
}

int CountStud()
{
	ifstream fin("inStud.txt");
	CheckInputFile(fin);
	char temp[100];
	int counter = 1;
	while (fin.getline(temp, 100))
	{
		counter++;
	}
	fin.close();
	return counter;
}

void ChoiceSortGroup(Student* arr, const int& size) // group
{
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j].group < arr[min].group)
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(arr[min], arr[i]);
		}
	}
}

void SortSurname(Student* arr, const int& size)
{
	char temp[100];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[i].group > arr[j].group)
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[i].group == arr[j].group && strcmp(arr[i].surname, arr[j].surname) > 0)
			{
				swap(arr[i], arr[j]);
			}
		}
	}

}

void CompletionStud(Student* arr, const int& size)
{
	ifstream fin("inStud.txt");
	CheckInputFile(fin);
	int i = 0;
	while (fin >> arr[i].card)
	{
		fin >> arr[i].surname >> arr[i].name >> arr[i].patronymic;
		i++;
	}
	fin.close();
}

void CompletionMarks(Student* arr, const int& size)
{
	ifstream fin("inMark.txt");
	Student* temp = new Student[size];
	CheckInputFile(fin);
	int i = 0;
	while (fin >> temp[i].group)
	{
		fin >> temp[i].card >> temp[i].mark_geo >> temp[i].mark_ma >> temp[i].mark_prog;
		i++;
	}
	fin.clear();
	fin.seekg(0);
	fin.close();
	for (i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i].card == temp[j].card)
			{
				arr[i].group = temp[j].group;
				arr[i].mark_geo = temp[j].mark_geo;
				arr[i].mark_ma = temp[j].mark_ma;
				arr[i].mark_prog = temp[j].mark_prog;
				arr[i].average = round((arr[i].mark_geo + arr[i].mark_ma + arr[i].mark_prog) / 3.0);
			}
		}
	}
}

void FormBinFile(Student* arr, const int& size)
{
	ofstream fout("out.bin", ios::binary);
	CheckFout(fout);
	fout.write((char*)&arr, sizeof(arr));
	fout.close();
}

void FormBinFileWorst(Student* arr, const int& size, AdvStud* worst, const int& numb)
{
	ofstream fout("out.bin", ios::binary);
	CheckFout(fout);
	size_t j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].average <= 5)
		{
			worst[j].card = arr[i].card;
			worst[j].group = arr[i].group;
			strcpy(worst[j++].surname, arr[i].surname);
		}
	}
	fout.write((char*)&worst, sizeof(worst));
	fout.close();
}

void FormBinFileBest(Student* arr, const int& size, AdvStud* best, const int& numb)
{
	ofstream fout("out.bin", ios::binary);
	CheckFout(fout);
	size_t j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].average >= 8)
		{
			best[j].card = arr[i].card;
			best[j].group = arr[i].group;
			strcpy(best[j++].surname, arr[i].surname);
		}
	}
	fout.write((char*)&best, sizeof(best));
	fout.close();
}

void Print1(ifstream& fin, Student* arr, const int& size)
{
	Student* temp = new Student[size];
	fin.read((char*)&temp, sizeof(arr));
	for (size_t i = 0; i < size; i++)
	{
		cout << temp[i].group << ' '
			<< temp[i].card << ' '
			<< temp[i].surname << ' '
			<< temp[i].name << ' '
			<< temp[i].patronymic << ' '
			<< temp[i].mark_geo << ' '
			<< temp[i].mark_ma << ' '
			<< temp[i].mark_prog << ' '
			<< endl;
	}
	delete[]temp;
}

void Print2(ifstream& fin, Student* arr, const int& size)
{
	Student* temp = new Student[size];
	fin.read((char*)&temp, sizeof(arr));
	for (size_t i = 0; i < size; i++)
	{
		cout << temp[i].group << ' '
			<< temp[i].card << ' '
			<< temp[i].surname << ' '
			<< temp[i].name << ' '
			<< temp[i].patronymic << ' '
			<< temp[i].mark_geo << ' '
			<< temp[i].mark_ma << ' '
			<< temp[i].mark_prog << ' '
			<< temp[i].average << ' '
			<< endl;
	}
	delete[]temp;
}

void Print3(ifstream& fin, AdvStud* arr, const int& size)
{
	fin.read((char*)&arr, sizeof(arr));
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i].group << ' '
			<< arr[i].card << ' '
			<< arr[i].surname << ' '
			<< endl;
	}
}

int comp_group(const void* i, const void* j)
{
	return ((Student*)i)->group - ((Student*)j)->group;
}

int comp_alp(const void* i, const void* j)
{
	return _stricmp(((Student*)i)->surname, ((Student*)j)->surname);
}

int comp_avg(const void* i, const void* j)
{
	return ((Student*)j)->average - ((Student*)i)->average;
}

int comp_all(const void* i, const void* j)
{
	if (comp_group(i, j) != 0)
	{
		return comp_group(i, j);
	}
	if (comp_alp(i, j) != 0)
	{
		return comp_alp(i, j);
	}
	return 0;
}

void PrintInfile1(const int& size, Student* arr)
{
	ofstream fout("result.txt", ios::ate);
	for (size_t i = 0; i < size; i++)
	{
		fout << arr[i].group << ' '
			<< arr[i].card << ' '
			<< arr[i].surname << ' '
			<< arr[i].name << ' '
			<< arr[i].patronymic << ' '
			<< arr[i].mark_geo << ' '
			<< arr[i].mark_ma << ' '
			<< arr[i].mark_prog << ' '
			<< endl;
	}
	fout.close();
}

void PrintInfile2(const int& size, Student*arr)
{
	ofstream fout("result.txt");
	for (size_t i = 0; i < size; i++)
	{
		fout << arr[i].group << ' '
			<< arr[i].card << ' '
			<< arr[i].surname << ' '
			<< arr[i].name << ' '
			<< arr[i].patronymic << ' '
			<< arr[i].mark_geo << ' '
			<< arr[i].mark_ma << ' '
			<< arr[i].mark_prog << ' '
			<< arr[i].average << ' '
			<< endl;
	}
	fout.close();
}

void PrintInfile3(const int& size, AdvStud* arr)
{
	ofstream fout("result.txt");
	for (size_t i = 0; i < size; i++)
	{
		fout << arr[i].group << ' '
			<< arr[i].card << ' '
			<< arr[i].surname << ' '
			<< endl;
	}
	fout.close();
}

int CounterWorst(Student* arr, const int& size)
{
	int counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].average <= 5)
		{
			counter++;
		}
	}
	return counter;
}

int CounterBest(Student* arr, const int& size)
{
	int counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].average >= 8)
		{
			counter++;
		}
	}
	return counter;
}

int CounterGroup(Student* arr, const int& size, const int& group)
{
	int counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].group == group)
		{
			counter++;
		}
	}
	return counter;
}

void CheckGroup(const int& group)
{
	if (group < 3 || group > 6)
	{
		throw"this group is not exist";
	}
}

void FormSpecGroup(Student* arr, const int& size, Student* temp, const int& numb, const int& group)
{
	size_t j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].group == group)
		{
			temp[j].average = arr[i].average;
			temp[j].card = arr[i].card;
			temp[j].group = arr[i].group;
			temp[j].mark_geo = arr[i].mark_geo;
			temp[j].mark_ma = arr[i].mark_ma;
			temp[j].mark_prog = arr[i].mark_prog;
			strcpy(temp[j].patronymic, arr[i].patronymic);
			strcpy(temp[j].name, arr[i].name);
			strcpy(temp[j++].surname, arr[i].surname);
		}
	}
}
