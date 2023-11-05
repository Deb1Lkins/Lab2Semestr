#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#ifndef RingListChar_H
#define RingListChar_H
class RingListChar : public List
{
private:
	struct Node
	{
		Node* next;
		char* data;
		Node(char* data, Node* next = nullptr)
		{
			this->data = new char[strlen(data) + 1];
			strcpy(this->data, data);
			this->next = next;
		}
	};
	int size;
	Node* head, *tail;
	void Clone(const RingListChar&);
	virtual void Erase() override;
public:
	RingListChar();
	RingListChar(const RingListChar&);
	virtual ~RingListChar();
	virtual void DelHead() override;
	virtual void Print() override;
	int GetSize();
	void push(char* data);
	const RingListChar& operator=(const RingListChar&);
};
#endif

