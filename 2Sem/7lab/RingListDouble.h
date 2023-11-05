#include "List.h"
#ifndef RingListDouble_H
#define RingListDouble_H
class RingListDouble : public List
{
private:
	struct Node
	{
		Node* next;
		double data;
		Node(double data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int size;
	Node* head, * tail;
	void Clone(const RingListDouble&);
	virtual void Erase() override;
public:
	RingListDouble();
	RingListDouble(const RingListDouble&);
	virtual ~RingListDouble();
	virtual void DelHead() override;
	virtual void Print() override;
	int GetSize();
	void push(double data);
	const RingListDouble& operator=(const RingListDouble&);
};
#endif

