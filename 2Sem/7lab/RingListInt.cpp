#include "RingListInt.h"

void RingListInt::Clone(const RingListInt& other)
{
	Node* cur = other.head;
	for (size_t i = 0; i < other.size; i++)
	{
		this->push(cur->data);
		cur = cur->next;
	}
}

void RingListInt::Erase()
{
	for (size_t i = 0; i < size; i++)
	{
		DelHead();
	}
}

RingListInt::RingListInt() : size(0), head(nullptr), tail(nullptr) {}

RingListInt::RingListInt(const RingListInt& other)
{
	Clone(other);
	size = other.size;
}

RingListInt::~RingListInt()
{
	Erase();
}

void RingListInt::DelHead()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		tail = head->next;
		delete temp;
		size--;
	}
}

void RingListInt::Print()
{
	if (head == nullptr)
	{
		cout << "очередь пуста" << endl;
		return;
	}
	Node* cur = head;
	for (size_t i = 0; i < size; i++)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}

int RingListInt::GetSize()
{
	return size;
}

void RingListInt::push(int data)
{
	Node* temp = new Node(data);
	temp->data = data;
	if (size == 0)
	{
		head = tail = temp;
		size++;
	}
	else
	{
		temp->next = head;
		tail->next = temp;
		head = temp;
		size++;
	}
}

const RingListInt& RingListInt::operator=(const RingListInt& other)
{
	if (this != &other)
	{
		Erase();
		Clone(other);
	}
	return *this;
}
