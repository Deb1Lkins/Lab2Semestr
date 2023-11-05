
#include "Magician.h"
#include <cassert>

void InputArr(size_t* arr, const size_t& begin, const size_t& end)
{
	srand(time(NULL));
	const int max_num = 100;
	for (size_t i = begin; i < end; i++)
	{
		arr[i] = rand() % max_num;
	}
}

Magician::Magician() :RPGamer(), max_mana(0), mana(0), arr(nullptr), size(0) {}

Magician::Magician(char* name, condition condit, species race, bool move, int max_mana, int mana, int size) : RPGamer(name, condit, race, move), max_mana(max_mana), mana(mana), size(size)
{
	assert(size <= 12);
	assert(max_mana >= mana);
	arr = new size_t[size];
	InputArr(arr, 0, size);
}

Magician::Magician(const Magician& other) : RPGamer(other.name, other.condit, other.race, other.move), max_mana(other.max_mana), mana(other.mana), size(other.size)
{
	arr = new size_t[other.size];
	for (size_t i = 0; i < other.size; i++)
	{
		arr[i] = other.arr[i];
	}
}

Magician::~Magician()
{
	if (arr != nullptr)
	{
		delete[]arr;
	}
	arr = nullptr;
}

void Magician::SetMaxMana(int num)
{
	assert(num > this->mana);
	this->max_mana = num;
}

void Magician::SetMana(int num)
{
	assert(num <= this->max_mana);
	this->mana = num;
}

void Magician::SetSize(int num)
{
	assert(num <= 12);
	srand(time(NULL));
	if (arr == nullptr)
	{
		arr = new size_t[num];
		InputArr(arr, 0, size);
		this->size = num;
	}
	else
	{
		if (num > size)
		{
			size_t* temp = new size_t[this->size];
			for (size_t i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = new size_t[num];
			for (size_t i = 0; i < this->size; i++)
			{
				arr[i] = temp[i];
			}
			InputArr(arr, this->size - 1, num);
			delete[]temp;
		}
		else
		{
			if (num < size)
			{
				size_t* temp = new size_t[this->size];
				for (size_t i = 0; i < size; i++)
				{
					temp[i] = arr[i];
				}
				delete[]arr;
				arr = new size_t[num];
				for (size_t i = 0; i < num; i++)
				{
					arr[i] = temp[i];
				}
				delete[]temp;
			}
		}
		
	}
}

int Magician::GetMaxMana()
{
	return max_mana;
}

int Magician::GetMana()
{
	return mana;
}

int Magician::GetSize()
{
	return size;
}

Magician& Magician::operator=(const Magician& other)
{
	if (this != &other)
	{
		RPGamer::operator=(other);
		this->max_mana = other.max_mana;
		this->mana = other.mana;
		this->SetSize(other.size);
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	return *this;
}

bool Magician::operator==(const Magician& other)
{
	return RPGamer::operator==(other) && max_mana == other.max_mana && mana == other.mana && size == other.size;
}

void Magician::Print()
{
	cout << *this;
}

ostream& operator<<(ostream& os, Magician& other)
{
	os << static_cast<RPGamer&>(other);
	os << "Max mana: " << other.max_mana << endl
		<< "Current mana: " << other.mana << endl
		<< "Size of arr: " << other.size << endl
		<< "Arr: ";
	for (size_t i = 0; i < other.size; i++)
	{
		os << other.arr[i] << ' ';
	}
	os << endl;
	return os;
}
