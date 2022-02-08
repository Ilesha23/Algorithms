#pragma once
#include <iostream>
#include <cstddef>
using namespace std;

struct Node
{
	Node* Prev, * Next;
	int number;
};

class List {
	Node* Head, * Tail;
public:
	int count;
	List() {
		Head = Tail = NULL;
		count = 0;
	}
	~List() {
		while (Head)
		{
			Tail = Head->Next;
			delete Head;
			Head = Tail;
		}
	}
	void insert(int x) {
		Node* temp = new Node;
		temp->Next = NULL;
		temp->number = x;
		if (Head)
		{
			temp->Prev = Tail;
			Tail->Next = temp;
			Tail = temp;
		}
		else
		{
			temp->Prev = NULL;
			Head = Tail = temp;
		}
		count++;
	}
	void del(int num) {
		if (num <= count && num > 0)
		{
			Node* temp = Head;
			for (int i = 0; i < count - 1; i++)
			{
				temp = temp->Next;
				if (i = num)
				{
					temp->Prev->Next = temp->Next;
					temp->Next->Prev = temp->Prev;
					delete temp;
					count--;
				}
			}
		}
	}
	void swap(int num) {
		if (num <= (count - 1) && num > 0)
		{
			Node* temp1 = Head;
			Node* temp2 = Head;
			for (int i = 1; i < count; i++)
			{
				if ((i == num) && (num < count - 1))
				{
					int a = temp1->number;
					temp1->number = temp1->Next->number;
					temp1->Next->number = a;
				}
				temp1 = temp1->Next;
			}
		}
	}
	void combine(List list) {
		////////////////////////////////////////////////////////////////////////////////////////дописать
	}
	void showForward() {
		Node* temp = Head;
		while (temp)
		{
			cout << temp->number << endl;
			temp = temp->Next;
		}
		cout << "Amount is: " << count << endl;
	}
	void showBackward() {
		Node* temp = Tail;
		while (temp)
		{
			cout << temp->number << endl;
			temp = temp->Prev;
		}
		cout << "Amount is: " << count << endl;
	}
};
