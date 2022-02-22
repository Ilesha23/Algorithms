#pragma once
#include <cstddef>

using namespace std;

struct Node
{
	Node* Next;
	int data;
};


class Stack {
private:
	Node* Head, * Tail;

public:
	int count;
	Stack() {
		Head = Tail = NULL;
		count = 0;
	}
	~Stack() {
		popAll();
	}
	void push(int x) {
		Node* temp = new Node;
		temp->data = x;
		if (Head)
		{
			temp->Next = Head;
			Head = temp;
		}
		else
		{
			Head = Tail = temp;
		}
		count++;
	}
	void pop() {
		if (Head == Tail)
		{
			Head = Tail = NULL;
			count--;
		}
		else if (Head)
		{
			Node* temp = Head;
			Head = Head->Next;
			delete temp;
			count--;
		}
		else
		{
			cout << "Empty" << endl;
		}
	}
	void pop(int n) {
		if (n >= 0 && n < count)
		{
			Node* temp = Head;
			if (n == 0)
			{
				Head = Head->Next;
				delete temp;
			}
			else if (n == count - 1)
			{
				Node* temp2 = Head;
				temp = Tail;
				while (temp2)
				{
					if (temp2->Next == Tail)
					{
						Tail = temp2;
						delete temp;
						break;
					}
					temp2 = temp2->Next;
				}
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					if (n - 1 == i)
					{
						Node* temp2 = temp->Next;
						temp->Next = temp->Next->Next;
						delete temp2;
						break;
					}
					temp = temp->Next;
				}
			}
			count--;
		}
	}
	void popAll() {
		while (Head)
		{
			pop();
		}
	}
	void popEverySecond() {
		if (Head)
		{
			int q = 0;
			for (int i = 0; i < count; i++)
			{
				if (i % 2 == 0)
				{
					pop(q);
					q--;
				}
				q++;//эл с которого начинается удаление;
			}
		}
	}
	void swapFirstLast() {
		if (Head)
		{
			int q = Head->data;
			Head->data = Tail->data;
			Tail->data = q;
		}
	}
	void turnOver() {
		Stack q;
		Node* temp1 = Head;
		while (temp1 != Tail->Next)
		{
			q.push(temp1->data);
			temp1 = temp1->Next;
		}
		//*this = q;							 ДОПИСАТЬ
		Head = q.Head;
		this->show();
		delete temp1;
	}
	void show() {
		Node* temp = Head;
		while (temp != Tail->Next)
		{
			cout << temp->data << endl;
			temp = temp->Next;
		}
		cout << "Amount: " << count << endl;
	}
};