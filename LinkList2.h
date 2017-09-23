#include "stdafx.h"

class doubleLinkList
{
	//template<class T>
	class Node
	{
	public :
		int data;
		Node *node=nullptr;
		Node *parent = nullptr;

	};
	int length;
public:
	Node *head=nullptr;	
	Node *end = nullptr;
	doubleLinkList()
	{
		length = 0;
	}
	~doubleLinkList()
	{
		Node *temp;
		for (int i = 0; i < length; i++)
		{
			if (head==nullptr)
			{
				break;
			}
			temp= head;
			head= head->node;
			delete temp;
			temp = nullptr;
		}
		

	}
	int getLength()
	{
		return length;
	}
	 void push(int elem)
	{
		Node *temp = new Node(); 
		Node *rom=nullptr;
		temp->data = elem;
		if (head==nullptr)
		{
			head = temp;
		}
		else
		{
			end->node = temp;
			rom = end;
		}
		end = temp;
		end->parent = rom;
		length++;
	}
	 void push(int elem, int index)
	 {
		 if (index >= length)
		 {
			 std::cout << "下标越界" << std::endl;
			 return;
		 }
		 if (index==length-1)
		 {
			 push(elem);
			 return;
		 }
		 Node *temp = new Node();
		 Node *temp2 = nullptr;
		 Node *rom = head;
		 temp->data = elem;
		 for (int i = 0; i < index; i++)
		 {
			 rom=rom->node;
		 }
		 if (index==-1)
		 {
			 head->parent = temp;
			 temp->node = head;
			 head = temp;
		 }
		 else
		 {
			 temp2 = rom->node;
			 rom->node = temp;
			 temp->parent = rom;
			 temp->node = temp2;
			 temp2->parent = temp;
		 }
	 }
	 void pop()
	 {
		 Node *temp = end;
		 end = end->parent;
		 length--;
		 delete temp;
	 }
	 void pop(int index)
	 {
		 if (index>=length)
		 {
			 std::cout << "下标越界" << std::endl;
			 return;
		 }
		 if (index == length - 1)
		 {
			 this->pop();
			 return;
		 }
		 Node *temp = head;
		 Node *rom=nullptr;
		 for (int i = 0; i < index; i++)
		 {
			 temp = temp->node;
		 }
		 if (index!=0)
		 {
			 rom = temp->node;
			 temp->node = rom->node;
			 rom->node->parent = temp;
		 }
		 else
		 {
			 head = head->node;
			 head->parent = nullptr;
		 }	 
		 length--;
		 delete rom;
		 rom = nullptr;
	 }
	int get(int index)
	{
		if (index>=length)
		{
			std::cout << "下标越界"<<std::endl;
			return -1;
		}
		Node *t = head;
		for (int i = 0; i < index; i++)
		{
			t = t->node;
			if (t->node==nullptr)
			{
				break;
			}
		}
		int v = t->data;
		return v;
	}
};