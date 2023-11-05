#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<Windows.h>
using namespace std;
void CheckStr(char* str);
char* maxWord(char*, char*, int&);
char* minWord(char*, char*, int&);
char* SwapWordsInStr(char*, char*, int, char*, int, const char*);
void Run()
{
    try
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        char str[300], copy[300], delim[] = " !,.;:-?@#$%^&*()_{}[]";
        char* pMax = 0, *pMin = 0;
        int max_len = 0, min_len = 0;
        //hii,helloosdfsf,hi34,by,wrety
        cout << "������� ������\n";
        cin.getline(str, 100);
        CheckStr(str);
        strcpy(copy, str);
        pMax = maxWord(str, delim, max_len);
        cout << "������������ ����� " << pMax << "\n";
        strcpy(str, copy);
        pMin = minWord(str, delim, min_len);
        cout << "����������� ����� " << pMin << "\n";
        strcpy(str, copy);
        cout << SwapWordsInStr(str, pMax, max_len, pMin, min_len, delim);
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}
int main() 
{
    Run();
    
    return 0;
}
void CheckStr(char* str)
{
	if (strlen(str) == 0)
	{
		throw"������ �����";
	}
}
char* maxWord(char* str, char* delim, int& max_len)
{
    int cur_len, counter = 1;
    char* maxWord = 0;
    char* word = strtok(str, delim);
    while (word)
    {
        cur_len = strlen(word);
        if (cur_len > max_len)
        {
            max_len = cur_len;
            maxWord = word;
        }
        word = strtok(NULL, delim);
        counter++;
    }
    if (max_len == 0)
    {
        throw " ������ ������ �� ���������� ";
    }
    if (counter < 2)
    {
        throw"� ������ ������ 2 ����";
    }
    return maxWord;
}
char* minWord(char* str, char* delim, int& min_len)
{
    int cur_len;
    char* minWord = 0;
    char* word = strtok(str, delim);
    min_len = strlen(word);
    while (word)
    {
        cur_len = strlen(word);
        if (cur_len <= min_len)
        {
            min_len = cur_len;
            minWord = word;
        }
        word = strtok(NULL, delim);
    }
    if (min_len == 0)
    {
        throw "������ ������ �� ���������� ";
    }
    return minWord;
}
char* SwapWordsInStr(char* str, char* pMax, int max_len, char* pMin, int min_len, const char* delim)
{
    cout << str << endl;
    int diff = max_len - min_len;
    int length = strlen(str);
    char* iMax = pMax, *iMin = pMin;
    char* max_copy = new char[max_len];
    strcpy(max_copy, pMax);
    int i = 0;
    for (i; i < min_len; i++) //�� ����� ���� ���
    {
        iMax[i] = iMin[i];
    }
    i = 0;
    while (iMax[max_len + i])//��� ��� ����� ���� � ����� ���
    {
        iMax[min_len + i] = iMax[max_len + i];
        i++;
    }
    if (iMin > iMax)//�������� ��� ����� ��� �����
    {
        iMin -= diff;
    }
    else {
        int j = length - 1;
        while (iMin != iMax + i)//������� �����
        {
            str[j] = iMax[min_len + i - 1];
            i--;
            j--;
        }
    }
    for (int i = 0; i < max_len; i++)//���� �� ��� �����
    {

        iMin[i] = max_copy[i];
    }
    return str;
}