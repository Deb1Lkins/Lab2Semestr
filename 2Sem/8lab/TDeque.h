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
	struct TDequeItem // ������� ����
	{
		type info; // ������
		TDequeItem* next; // ��������� �� ��������� �������
		TDequeItem* prev; // ��������� �� ���������� �������
	};
	/* ��������� �� ������ � ��������� �������� � ������ */
	TDequeItem* front, * rear;
	int size; // ���������� ��������� � ����
	void Erase(); // �������� ���� ��������� +
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
	} // �������� �������� �� ��������� +
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
	}//��������� �� ������� � �������� �������� +
public:
	TDeque(); // ����������� +
	TDeque(const TDeque& other); // ����������� ����������� +
	virtual ~TDeque(); // ���������� +
	int GetSize() { return size; }
	void InsFront(type info); // �������� ������� � ������ ���� +
	void InsRear(type info); // �������� ������� � ����� ���� +
	bool DelFront(); // ��������� ������� �� ������ ���� +
	bool DelRear(); // ��������� ������� �� ������ ���� +
	const TDeque<type>& operator = (const TDeque& other);// �������� ������������ +
	const type& GetByIndex(unsigned i)const; // �������� ������� �� ������� +
	void SetByIndex(type info, unsigned i); // �������� ������� �� ������� +
	void Browse(void(type& info)); // �������� � ���������� ��������� 
	void Browse(void(type info)) const; // �������� ��� ��������� ���������
};
template<>
class TDeque <char*>
{
private:
	struct TDequeItem // ������� ����
	{
		char* info; // ������
		TDequeItem* next; // ��������� �� ��������� �������
		TDequeItem* prev; // ��������� �� ���������� �������
	};
	/* ��������� �� ������ � ��������� �������� � ������ */
	TDequeItem* front, * rear;
	int size; // ���������� ��������� � ����
	void Erase()
	{
		for (size_t i = 0; i <= size; i++)
		{
			DelFront();
		}
	}// �������� ���� ��������� +
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
	} // �������� �������� �� ��������� +
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
	}//��������� �� ������� � �������� �������� +
public:
	TDeque() : front(nullptr), rear(nullptr), size(0) {};// ����������� +
	TDeque(const TDeque& other)
	{
		if (this != &other)
		{
			this->Clone(other);
		}
	}// ����������� ����������� +
	virtual ~TDeque() { Erase(); } // ���������� +
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
	} // �������� ������� � ������ ���� +
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
	}// �������� ������� � ����� ���� +
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
	}// ��������� ������� �� ������ ���� +
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
	}// ��������� ������� �� ������ ���� +
	const TDeque<char*>& operator = (const TDeque& other)
	{
		if (this != &other)
		{
			this->Erase();
			this->Clone(other);
		}
		return *this;
	}// �������� ������������ +
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
	}// �������� ������� �� ������� +
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
	}// �������� ������� �� ������� +
	void Browse(void Func(char*& info))
	{
		for (size_t i = 0; i < size; i++)
		{
			Func(PtrByIndex(i)->info);
		}
	}// �������� � ���������� ���������
	void Browse(void Func(const char* info)) const
	{
		for (size_t i = 0; i < size; i++)
		{
			Func(GetByIndex(i));
		}
	}// �������� ��� ��������� ���������
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

