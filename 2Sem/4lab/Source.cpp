#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;
void CheckStr(char* str);
void InPutDelims(char* delims);
void NewStr(char* str, char* delims);
bool IfOnlyAlpha(char* word);
void WordRevers(char* word);
bool IfOnlyAlphaAndNum(char* word);
void ChangeWord(char* word);
void AddToEnd(char* new_str, char* word, size_t& i);
void CreateNewStr(char*& new_str, char* str, char* delims);
void Run()
{
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int max_size = 300;
		char* str = new char[max_size];
		cout << "введите строку:\n";
		//hi,helloo,hi345,by,2343,wreterwty
		cin.getline(str, max_size);
		CheckStr(str);
		char* delims = new char[max_size];
		InPutDelims(delims);

		NewStr(str, delims);


		delete[]str;
		delete[]delims;
		cout << "\nпрограмма закончила свою работу";
	}
	catch (const char* msg)
	{
		cout << msg;
	}

}
int main()
{
	Run();
	return 0;
}
/*Дана строка, слова в которой состоят из букв латинского алфавита и десятичных цифр.
Остальные символы считаются разделителями между словами. Получить новую строку, выполняя в заданной строке замены по следующему правилу.
Все слова, имеющие длину более 4 символов и состоящие только из букв, заменяются словами, записанными в обратном порядке.
Во всех  словах, в которых встречаются как буквы, так и цифры, строчные буквы заменяются на прописные.
Слова в новой строке должны разделяться ровно одним пробелом. */
void CheckStr(char* str)
{
	if (strlen(str) == 0) { throw"пустая строка\n"; }
}
void InPutDelims(char* delims)
{
	for (size_t i = 1; i < 256; i++)
	{
		if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
		{
			continue;
		}
		delims[i] = char(i);
	}
	delims[256] = '\0';

}
void NewStr(char* str, char* delims)
{
	size_t size = strlen(str);
	char* new_str = new char[size + 1];
	char* word = strtok(str, delims);
	size_t i = 0;
	bool done = false;
	while (word)
	{
		if (strlen(word) >= 4)
		{
			if (IfOnlyAlpha(word))
			{
				WordRevers(word);
				done = true;
			}
		}
		if (!done && IfOnlyAlphaAndNum(word))
		{
			ChangeWord(word);
		}
		AddToEnd(new_str, word, i);
		word = strtok(NULL, delims);
		new_str[i++] = ' ';
		done = false;
	}
	new_str[--i] = '\0';
	cout << endl << new_str << endl;
	delete[]new_str;
}
void AddToEnd(char* new_str, char* word, size_t& i)
{
	size_t size = i + strlen(word), j = 0;
	for (i; i < size; i++)
	{
		new_str[i] = word[j++];
	}
}
void CreateNewStr(char*& new_str, char* str, char* delims)
{
	char copy[300];
	strcpy(copy, str);
	char* word = strtok(copy, delims);
	size_t size = strlen(word);
	while (word)
	{
		word = strtok(NULL, delims);
		size += strlen(word);
	}
	new_str = new char[size];
}
bool IfOnlyAlpha(char* str)
{
	const size_t size = strlen(str);
	for (size_t i = 0; i < size; i++)
	{
		if (!isalpha(str[i]))
		{
			return false;
		}
	}
	return true;
}
void WordRevers(char* word)
{
	int j = strlen(word) - 1, size;
	size = (int)j / 2;
	for (size_t i = 0; i <= size; i++)
	{
		swap(word[i], word[j--]);
	}
}
bool IfOnlyAlphaAndNum(char* word)
{

	const size_t size = strlen(word);
	for (size_t i = 0; i < size; i++)
	{
		if (!isalnum(word[i]))
		{
			return false;
		}
	}
	return true;
}
void ChangeWord(char* word)
{
	const size_t size = strlen(word);
	for (size_t i = 0; i <= size; i++)
	{
		if (isalpha(word[i]) && islower(word[i]))
		{
			word[i] = (char)toupper(word[i]);
		}
	}
}

