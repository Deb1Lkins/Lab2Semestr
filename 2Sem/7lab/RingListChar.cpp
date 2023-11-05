#include "RingListChar.h"

void RingListChar::Clone(const RingListChar& other)
{
	Node* cur = other.head;
	for (size_t i = 0; i < other.size; i++)
	{
		this->push(cur->data);
		cur = cur->next;
	}
}

void RingListChar::Erase()
{
	for (size_t i = 0; i < size; i++)
	{
		DelHead();
	}
}

RingListChar::RingListChar() : size(0), head(nullptr), tail(nullptr) {}

RingListChar::RingListChar(const RingListChar& other)
{
	Clone(other);
	size = other.size;
}

RingListChar::~RingListChar()
{
	Erase();
}

void RingListChar::DelHead()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		tail = head->next;
		delete temp->data;
		delete temp;
		size--;
	}
}

void RingListChar::Print()
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

int RingListChar::GetSize()
{
	return size;
}

void RingListChar::push(char* data)
{
	Node* temp = new Node(data);
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

const RingListChar& RingListChar::operator=(const RingListChar& other)
{
	if (this != &other)
	{
		Erase();
		Clone(other);
	}
	return *this;
}
