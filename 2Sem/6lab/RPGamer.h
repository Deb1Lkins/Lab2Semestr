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
/*Разработать многомодульное приложение.
1) Создать класс «персонаж ролевой игры». Включить в описание класса следующие
поля: - max 6
- уникальный числовой идентификатор, заполняется автоматически при создании объекта
(константное поле);
- имя персонажа;
- состояние (нормальное, парализован, мертв);
- раса (человек, гном, эльф) (константное поле);
- возможность двигаться.
Реализовать:
- все конструкторы, обеспечивающие уникальность идентификатора для нового объекта;
- перегрузить операцию присваивания =;
- get-методы для всех полей;
- set-методы для тех полей, которые можно изменять;
- перегрузку оператора ==;
- вывод сведений об объекте в выходной поток.
Реализовать также необходимые, но не названные методы. Использовать тип enum.
Продемонстрировать работу всех методов.*/
