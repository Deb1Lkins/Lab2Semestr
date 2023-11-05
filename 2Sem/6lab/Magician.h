#ifndef Magician_H
#define Magician_H
#include "RPGamer.h"
class Magician : public RPGamer
{
private:
	int max_mana;
	int mana;
	size_t* arr;
	int size;
public:
	Magician();
	Magician(char* name, condition condit, species race, bool move, int max_mana, int mana, int size);
	Magician(const Magician& other);
	virtual ~Magician();
	void SetMaxMana(int num);
	void SetMana(int num);
	void SetSize(int num);

	int GetMaxMana();
	int GetMana();
	int GetSize();

	Magician& operator=(const Magician& other);
	bool operator==(const Magician& other);
	friend ostream& operator<<(ostream& os, Magician& other);
	void Print() override;
};
#endif Magician_H
/*2) ������� �����-������� ���������, ��������� ������. ������������� ��������
� �������� ����� ������ ��������� ����: - max 8
- ������������ ���������� ���������� ������� (����) � ����������� �����;
- ������� ���������� ���� � ����� ��������������� �����, �� �������������
������������� ����������;
- ������������ ������ ����� ����������� ����� - ���������� ���������� ������� ��
��������� ���������� ������� � ������ ����.
- ����������� ������������� ������� - ���������� ������� <=12 (�������� �� asssert) .
�����������:
- ��� ������������;
- get-������ � set-������ ��� ����� �����;
- ���������� �������� ������������ =;
- ����� �������� �� ������� � �������� �����.
������������������ ������ ���� �������. ����������� ���������� ��� ������� ��������
� set-������ �������� ���������.*/