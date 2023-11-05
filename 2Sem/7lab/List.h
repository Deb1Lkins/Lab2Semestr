#ifndef List_H
#define List_H
#include <iostream>
#include <cassert>
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
using namespace std;
class List
{
public:
	virtual void Print() = 0;
	virtual void Erase() = 0;
	virtual void DelHead() = 0;
};
#endif // !List