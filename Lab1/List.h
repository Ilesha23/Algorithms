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
		delAllList();
	}

	void delAllList() //реализация удаления всех элементов списка
	{
		while (Head != NULL) //пока не указываем на хвост
		{
			Node* pTemp = Head; //создаем временный элемент
			Head = Head->Next; //присваиваем ему указатель на следующий
			delete pTemp; // и удаляем его
		}

		Head = NULL;
		Tail = NULL;
		count = 0;
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
				if ((i == num) && (num < count))
				{
					int a = temp1->number;
					temp1->number = temp1->Next->number;
					temp1->Next->number = a;
				}
				temp1 = temp1->Next;
			}
		}
	}
	void swapptr(int num) {
		if (num <= (count - 1) && num > 0)
		{
			Node* temp1 = Head;
			Node* temp2 = temp1->Next;
			for (int i = 1; i < count; i++)
			{
				if ((i == num) && (num < count))
				{
					temp1->Next = temp2->Next;
					temp2->Prev = temp1->Prev;
					temp1->Prev = temp2;
					temp2->Next = temp1;
					temp1->Next->Prev = temp1;
					temp2->Prev->Next = temp2;
					temp1 = temp1->Prev;
					temp2 = temp1->Next;
				}
				temp1 = temp1->Next;
				temp2 = temp2->Next;
			}
		}
	}
	void combine(List list) {
		////////////////////////////////////////////////////////////////////////////////////////дописать
		Node* tmp = list.Head;
		while (tmp)
		{
			insert(tmp->number);
			tmp = tmp->Next;
		}
		delete tmp;
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
