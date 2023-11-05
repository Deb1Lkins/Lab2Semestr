#include "List.h"
#ifndef RingListInt_H
#define RingListInt_H
class RingListInt : public List
{
private:
	struct Node
	{
		Node* next;
		int data;
		Node(int data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int size;
	Node* head, *tail;
	void Clone(const RingListInt&);
	virtual void Erase() override;
public:
	RingListInt();
	RingListInt(const RingListInt&);
	virtual ~RingListInt();
	virtual void DelHead() override;
	virtual void Print() override;
	int GetSize();
	void push(int data);
	const RingListInt& operator=(const RingListInt&);
};
#endif 

