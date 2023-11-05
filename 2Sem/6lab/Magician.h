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
/*2) —оздать класс-потомок Ђперсонаж, владеющий магиейї. ƒополнительно включить
в описание этого класса следующие пол€: - max 8
- максимальное количество магической энергии (маны) Ц натуральное число;
- текущее количество маны Ц целое неотрицательное число, не превосход€щее
максимального количества;
- динамический массив целых беззнаковых чисел - количество магических сеансов за
указанное количество мес€цев с начала года.
- размерность динамического массива - количество мес€цев <=12 (проверка по asssert) .
–еализовать:
- все конструкторы;
- get-методы и set-методы дл€ новых полей;
- перегрузку операцию присваивани€ =;
- вывод сведений об объекте в выходной поток.
ѕродемонстрировать работу всех методов. ¬ыбрасывать исключени€ при попытке передать
в set-методы неверные параметры.*/