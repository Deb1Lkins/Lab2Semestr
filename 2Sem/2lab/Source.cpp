//Разработать шаблон функции, позволяющей в упорядоченный массив
//включить новый элемент так, чтобы не нарушилась упорядоченность.
//int, double, char*
#include <iostream>
#include <ctime>
#include <cstdlib>
using std:: cout;
using std::cin;
void CheckSize(const int& size)
{
	if (size <= 0)
	{
		throw"неправильные данные";
	}
}
void InputSize(int& size)
{
	cout << "введите размер - ";
	cin >> size;
	CheckSize(size);
}
template<class type>
void CreateArr(type*& arr, int& size)
{
	size++;
	arr = new type[size]; 
	size--;
}
template<class type>
void InPutArray(type* arr, const int& size)
{
	const int min = 65, max = 90;
	for (int i = 0; i < size; i++)
	{
		arr[i] = (type)rand() % (max - min + 1) + min;
	}
}
template<> 
void InPutArray<>(double* arr, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}
}
template<class type>
void PrintArray(type* arr, const int& size)
{
	cout << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << "   " << arr[i];
	}
}
int compareUpInt(const void* i, const void* j)
{
	return *(int*)i - *(int*)j;
}
int compareUpDouble(const void* i, const void* j)
{
	const double *a, *b;

	a = (const double*)i;
	b = (const double*)j;
	if (*a > *b)
	{
		return 1;
	}
	if (*a< *b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
template<class type>
int FindPosition(type* arr, const type& el, const int& size)
{
	bool flag = false;
	int position = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] < el)
		{
			flag = true;
		}
		if (flag && arr[i + 1] > el)
		{
			position = i + 1;
		}
		flag = false;
	}
	return position;
}
template<class type>
void IncludeInArray(type*& arr,const int& size)
{
	type el;
	cout << "\nвведите элемент массива - ";
	cin >> el;
	int position = FindPosition(arr, el, size);
	for (int i = position; i <= size; i++)
	{
		std::swap(el, arr[i]);
	}
}


void InPutArrayChar(char** arr, const int& size)
{
	const int min = 70, max = 90, length = 10;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < length; j++)
		{
			arr[i][j] = (char)rand() % (max - min + 1) + min;
		}
	}
}
void CreateArrChar(char**& arr, int& size)
{
	size++;
	arr = new char* [size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = new char[255];
	}
	size--;
}
void PrintArrayChar(char** arr, const int& size)
{
	cout << std::endl;
	const int length = 5;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << arr[i][j];
		}
		cout << "  ";
	}
}
bool CheckWords(char* arr1, char* arr2, const int& j)
{
	const int length = 5;
	for (size_t k = 0; k < length; k++)
	{
		if ((char)arr1[k] > (char)arr2[k])
		{
			return true;
		}
		else
		{
			if ((char)arr1[k] < (char)arr2[k])
			{
				return false;
			}
			else
			{
				continue;
			}
		}
	}
	return false;
}
void SortCharArr(char** arr,const int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			if (CheckWords(arr[j],arr[j+1], j))
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
char* InputEl()
{
	const int length = 5;
	char* temp = new char[length];
	cout << "\nвведите слово:\n";
	for (size_t i = 0; i < length; i++)
	{
		cin >> temp[i];
	}
	return temp;
}
int FindPos(char** arr,const int& size, char* temp)
{
	for (int i = 0; i < size; i++)
	{
		if (CheckWords(arr[i], temp, i))
		{
			return i;
		}
	}
}
void IncludeInArrayChar(char** arr, const int& size)
{
	char* temp = InputEl();
	const int position = FindPos(arr, size, temp);
	for (size_t i = position; i < size + 1; i++)
	{
		std::swap(temp, arr[i]);
	}
	delete[]temp;
}
void DeleteArrChar(char**& arr, const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	try
	{
		int choice;
		cout << "выберите тип данных для массива - "
			<< "\n1) int"
			<< "\n2) double"
			<< "\n3) char* - ";
		cin >> choice;
		int size;
		switch (choice)
		{
		case 1:
		{
			int* arr;
			InputSize(size);
			CreateArr(arr, size);
			InPutArray(arr, size);
			qsort(arr, size, sizeof(int), compareUpInt);
			PrintArray(arr, size);
			IncludeInArray(arr, size);
			PrintArray(arr, size+1);
			delete[]arr;
			break;
		}
		case 2:
		{
			double* arr;
			InputSize(size);
			CreateArr(arr, size);
			InPutArray(arr, size);
			qsort(arr, size, sizeof(double), compareUpDouble);
			PrintArray(arr, size);
			IncludeInArray(arr, size);
			PrintArray(arr, size+1);
			delete[]arr;
			break;
		}
		case 3:
		{
			char** arr;
			InputSize(size);
			CreateArrChar(arr, size);
			InPutArrayChar(arr, size);
			SortCharArr(arr, size);
			PrintArrayChar(arr, size);
			IncludeInArrayChar(arr, size);
			PrintArrayChar(arr, size+1);
			DeleteArrChar(arr, size);
			break;
		}
		default:
			cout << "не было выбрано";
			break;
		}
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	return 0;
}