#include <iostream>
#include <Windows.h>
using namespace std;
class Tree
{
private:
	class Node
	{
	public:
		int data;
		Node* pLeft;
		Node* pRight;
		Node(int data = int(), Node* pLeft = nullptr, Node* pRight = nullptr) : data(data), pLeft(pLeft), pRight(pRight)
		{
		}
	};
	Node* root;
	int size;
	void add_node(int data, Node*& node)
	{
		size++;
		if (node == nullptr)
		{
			node = new Node(data);
			node->pLeft = nullptr;
			node->pRight = nullptr;
		}
		else
		{
			if (data == node->data)
			{
				size--;
				cout << "такое число уже есть\n";
				return;
			}
			else
			{
				if (node->data > data)
				{
					this->add_node(data, node->pLeft);
				}
				else
				{
					this->add_node(data, node->pRight);
				}
			}
		}
	}
	void direct_order(Node* node); //прямой
	void symmetrical_order(Node* node); //симметр
	void free_tree(Node*& node);
public:
	int GetSize() { return size; }
	Tree();
	~Tree();
	void add_node(int data);
	void print_tree();

	

};

Tree::Tree() : size(0), root(nullptr)
{
}
Tree::~Tree()
{
	free_tree(root);
}
void Tree::free_tree(Node*& node)
{
	if (node != nullptr)
	{
		free_tree(node->pLeft);
		free_tree(node->pRight);
		delete node;
	}
}
void Tree::add_node(int data)
{
	this->add_node(data, this->root);
}
void Tree::print_tree()
{
	//direct_order(this->root);
	symmetrical_order(this->root);
}
void Tree::direct_order(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->data << "\t";
	direct_order(node->pLeft);
	direct_order(node->pRight);
	
}
void Tree::symmetrical_order(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	direct_order(node->pLeft);
	cout << node->data << "\t";
	direct_order(node->pRight);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Tree array;
	array.add_node(50);
	array.add_node(25);
	array.add_node(75);
	array.add_node(0);
	array.add_node(100);
	array.add_node(35);
	array.add_node(60);

	array.print_tree();

	return 0;
}


