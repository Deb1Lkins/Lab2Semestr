#include "RingListDouble.h"

void RingListDouble::Clone(const RingListDouble& other)
{
	Node* cur = other.head;
	for (size_t i = 0; i < other.size; i++)
	{
		this->push(cur->data);
		cur = cur->next;
	}
}

void RingListDouble::Erase()
{
	for (size_t i = 0; i < size; i++)
	{
		DelHead();
	}
}

RingListDouble::RingListDouble() : size(0), head(nullptr), tail(nullptr) {}

RingListDouble::RingListDouble(const RingListDouble& other)
{
	Clone(other);
	size = other.size;
}

RingListDouble::~RingListDouble()
{
	Erase();
}

void RingListDouble::DelHead()
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

void RingListDouble::Print()
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

int RingListDouble::GetSize()
{
	return size;
}

void RingListDouble::push(double data)
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

const RingListDouble& RingListDouble::operator=(const RingListDouble& other)
{
	if (this != &other)
	{
		Erase();
		Clone(other);
	}
	return *this;
}

