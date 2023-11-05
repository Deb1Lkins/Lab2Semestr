#ifndef RPGamer_H
#define RPGamer_H
#include <iostream>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
enum class condition { normaly = 0, paralyzed = 1, dead = 2};
enum class species { human = 0, elf = 1, dwarf = 2 };
class RPGamer
{
public:
	RPGamer();
	RPGamer(char* name, condition condit, species race, bool move);
	RPGamer(const RPGamer& other);
	virtual ~RPGamer();
	int GetId();
	char* GetName();
	condition GetCondit();
	species GetRace();
	bool GetMove();
	void SetName(char* name);
	void SetCondit(condition condit);
	void SetMove(bool move);
	RPGamer& operator=(const RPGamer& other);
	bool operator==(const RPGamer& other);
	//
	friend ostream& operator<<(ostream& out, RPGamer& other);
	//
	virtual void Print();
protected:
	const int id;
	char* name;
	condition condit;
	const species race;
	bool move;
};
#endif RPGamer_H
/*����������� �������������� ����������.
1) ������� ����� ��������� ������� �����. �������� � �������� ������ ���������
����: - max 6
- ���������� �������� �������������, ����������� ������������� ��� �������� �������
(����������� ����);
- ��� ���������;
- ��������� (����������, �����������, �����);
- ���� (�������, ����, ����) (����������� ����);
- ����������� ���������.
�����������:
- ��� ������������, �������������� ������������ �������������� ��� ������ �������;
- ����������� �������� ������������ =;
- get-������ ��� ���� �����;
- set-������ ��� ��� �����, ������� ����� ��������;
- ���������� ��������� ==;
- ����� �������� �� ������� � �������� �����.
����������� ����� �����������, �� �� ��������� ������. ������������ ��� enum.
������������������ ������ ���� �������.*/
