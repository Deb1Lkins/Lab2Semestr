#define _CRT_SECURE_NO_WARNINGS
#ifndef TDeque_H
#define TDeque_H
#include<iostream>
#include <cassert>
using namespace std;
template <class type>
class TDeque
{
private:
	struct TDequeItem // элемент дека
	{
		type info; // данные
		TDequeItem* next; // указатель на следующий элемент
		TDequeItem* prev; // указатель на предыдущий элемент
	};
	/* указатели на первый и последний элементы в списке */
	TDequeItem* front, * rear;
	int size; // количество элементов в деке
	void Erase(); // удаление всех элементов +
	void Clone(const TDeque& other); //+
	void DeleteItem(TDequeItem* other)
	{
		if (other == NULL)
		{
			return;
		}
		if (other->prev == NULL)
		{
			DelFront();
		}
		if (other->next == NULL)
		{
			DelRear();
		}
		TDequeItem* left = other->prev;
		TDequeItem* right = other->next;
		left->next = right;
		right->prev = left;
		size--;

		delete other;
	} // удаление элемента по указателю +
	TDequeItem* PtrByIndex(unsigned i)const
	{
		if (front != nullptr)
		{
			assert(i <= size);
			TDequeItem* curr = front;
			unsigned j = 0;
			while (j != i)
			{
				curr = curr->next;
				j++;
			}
			return curr;
		}
		return nullptr;
	}//указатель на элемент с заданным индексом +
public:
	TDeque(); // конструктор +
	TDeque(const TDeque& other); // конструктор копирования +
	virtual ~TDeque(); // деструктор +
	int GetSize() { return size; }
	void InsFront(type info); // включить элемент в голову дека +
	void InsRear(type info); // включить элемент в хвост дека +
	bool DelFront(); // исключить элемент из головы дека +
	bool DelRear(); // исключить элемент из хвоста дека +
	const TDeque<type>& operator = (const TDeque& other);// оператор присваивания +
	const type& GetByIndex(unsigned i)const; // получить элемент по индексу +
	void SetByIndex(type info, unsigned i); // изменить элемент по индексу +
	void Browse(void(type& info)); // просмотр с изменением элементов 
	void Browse(void(type info)) const; // просмотр без изменения элементов
};
template<>
class TDeque <char*>
{
private:
	struct TDequeItem // элемент дека
	{
		char* info; // данные
		TDequeItem* next; // указатель на следующий элемент
		TDequeItem* prev; // указатель на предыдущий элемент
	};
	/* указатели на первый и последний элементы в списке */
	TDequeItem* front, * rear;
	int size; // количество элементов в деке
	void Erase()
	{
		for (size_t i = 0; i <= size; i++)
		{
			DelFront();
		}
	}// удаление всех элементов +
	void Clone(const TDeque& other)
	{
		TDequeItem* curr = other.front;
		while (curr != other.rear)
		{
			InsRear(curr->info);
			curr = curr->next;
		}
		InsRear(curr->info);
		size = other.size;
	}//+
	void DeleteItem(TDequeItem* other)
	{
		if (other == NULL)
		{
			return;
		}
		if (other->prev == NULL)
		{
			DelFront();
		}
		if (other->next == NULL)
		{
			DelRear();
		}
		TDequeItem* left = other->prev;
		TDequeItem* right = other->next;
		left->next = right;
		right->prev = left;
		size--;

		delete other;
	} // удаление элемента по указателю +
	TDequeItem* PtrByIndex(unsigned i)const
	{
		if (front != nullptr)
		{
			assert(i <= size);
			TDequeItem* curr = front;
			unsigned j = 0;
			while (j != i)
			{
				curr = curr->next;
				j++;
			}
			return curr;
		}
		return nullptr;
	}//указатель на элемент с заданным индексом +
public:
	TDeque() : front(nullptr), rear(nullptr), size(0) {};// конструктор +
	TDeque(const TDeque& other)
	{
		if (this != &other)
		{
			this->Clone(other);
		}
	}// конструктор копирования +
	virtual ~TDeque() { Erase(); } // деструктор +
	int GetSize() { return size; }
	void InsFront(char* info)
	{
		TDequeItem* temp = new TDequeItem;
		temp->info = new char[strlen(info) + 1];
		strcpy(temp->info, info);
		if (size == 0)
		{
			front = rear = temp;
			size++;
		}
		else
		{
			temp->next = front;
			front = temp;
			temp->next->prev = temp;
			size++;
		}
	} // включить элемент в голову дека +
	void InsRear(char* info)
	{
		TDequeItem* temp = new TDequeItem;
		temp->info = new char[strlen(info) + 1];
		strcpy(temp->info, info);
		if (size == 0)
		{
			front = rear = temp;
			size++;
		}
		else
		{
			temp->prev = rear;
			rear = temp;
			temp->prev->next = temp;
			size++;
		}
	}// включить элемент в хвост дека +
	bool DelFront()
	{
		if (front != nullptr)
		{
			TDequeItem* temp = front->next;
			delete[]front->info;
			delete front;
			front = temp;
			size--;
			return true;
		}
		return false;
	}// исключить элемент из головы дека +
	bool DelRear()
	{
		if (rear != nullptr)
		{
			TDequeItem* temp = rear->prev;
			delete[]rear->info;
			delete rear;
			rear = temp;
			size--;
			return true;
		}
		return false;
	}// исключить элемент из хвоста дека +
	const TDeque<char*>& operator = (const TDeque& other)
	{
		if (this != &other)
		{
			this->Erase();
			this->Clone(other);
		}
		return *this;
	}// оператор присваивания +
	const char* GetByIndex(unsigned i)const
	{
		if (front != nullptr)
		{
			assert(i <= size);
			TDequeItem* curr = front;
			unsigned j = 0;
			while (j != i)
			{
				curr = curr->next;
				j++;
			}
			char* temp = new char[strlen(curr->info) + 1];
			strcpy(temp, curr->info);
			return temp;
		}
		return nullptr;
	}// получить элемент по индексу +
	void SetByIndex(char* info, unsigned i)
	{
		if (front != nullptr)
		{
			assert(i <= size);
			if (i == 0) { InsFront(info); }
			if (i == 0) { InsRear(info); }
			TDequeItem* curr = front;
			unsigned j = 0;
			while (j != i)
			{
				curr = curr->next;
				j++;
			}
			if (strlen(curr->info) < strlen(info))
			{
				delete[]curr->info;
				curr->info = new char[strlen(info) + 1];
			}
			strcpy(curr->info, info);
		}
	}// изменить элемент по индексу +
	void Browse(void Func(char*& info))
	{
		for (size_t i = 0; i < size; i++)
		{
			Func(PtrByIndex(i)->info);
		}
	}// просмотр с изменением элементов
	void Browse(void Func(const char* info)) const
	{
		for (size_t i = 0; i < size; i++)
		{
			Func(GetByIndex(i));
		}
	}// просмотр без изменения элементов
};
template<class type>
void TDeque<type>::Erase()
{
	for (size_t i = 0; i <= size; i++)
	{
		DelFront();
	}
}
template<class type>
void TDeque<type>::Clone(const TDeque& other)
{
	TDequeItem* curr = other.front;
	while (curr != other.rear)
	{
		InsRear(curr->info);
		curr = curr->next;
	}
	InsRear(curr->info);
	size = other.size;
}

template<class type>
TDeque<type>::TDeque() : front(nullptr), rear(nullptr), size(0) {};

template<class type>
TDeque<type>::TDeque(const TDeque& other)
{
	if (this != &other)
	{ 
		this->Clone(other);
	}
}
template<class type>
TDeque<type>::~TDeque()
{
	Erase();
}
template<class type>
void TDeque<type>::InsFront(type info)
{
	TDequeItem* temp = new TDequeItem;
	temp->info = info;
	if (size == 0)
	{
		front = rear = temp;
		size++; 
	}
	else
	{
		temp->next = front;
		front = temp;
		temp->next->prev = temp;
		size++;
	}
}
template<class type>
void TDeque<type>::InsRear(type info)
{
	TDequeItem* temp = new TDequeItem;
	temp->info = info;
	if (size == 0)
	{
		front = rear = temp;
		size++;
	}
	else
	{
		temp->prev = rear;
		rear = temp;
		temp->prev->next = temp;
		size++;
	}
}
template<class type>
bool TDeque<type>::DelFront()
{
	if (front != nullptr)
	{
		TDequeItem* temp = front->next;
		delete front;
		front = temp;
		size--;
		return true;
	}
	return false;
}
template<class type>
bool TDeque<type>::DelRear()
{
	if (rear != nullptr)
	{
		TDequeItem* temp = rear->prev;
		delete rear;
		rear = temp;
		size--;
		return true;
	}
	return false;
}
template<class type>
const TDeque<type>& TDeque<type>::operator=(const TDeque& other)
{
	if (this != &other)
	{
		this->Erase();
		this->Clone(other);
	}
	return *this;
}

template<class type>
const type& TDeque<type>::GetByIndex(unsigned i) const
{
	if (front != nullptr)
	{
		assert(i <= size);
		TDequeItem* curr = front;
		unsigned j = 0;
		while (j != i)
		{
			curr = curr->next;
			j++;
		}
		return curr->info;
	}
	return 0;
}
template<class type>
void TDeque<type>::SetByIndex(type info, unsigned i)
{
	if (front != nullptr)
	{
		assert(i <= size);
		if (i == 0) { InsFront(info); }
		if (i == 0) { InsRear(info); }
		TDequeItem* curr = front;
		unsigned j = 0;
		while (j != i)
		{
			curr = curr->next;
			j++;
		}
		curr->info = info;
	}
}
template<class type>
void TDeque<type>::Browse(void Func(type&))
{
	for (size_t i = 0; i < size; i++)
	{
		Func(PtrByIndex(i)->info);
	}
}
template<class type>
void TDeque<type>::Browse(void Func(type)) const
{
	for (size_t i = 0; i < size; i++)
	{
		Func(GetByIndex(i));
	}
}
#endif TDeque_H

