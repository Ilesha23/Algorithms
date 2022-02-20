#pragma once
#include <iostream>
#include <fstream>
#include "stdio.h"
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

	void delAllList()
	{
		while (Head != NULL)
		{
			Node* pTemp = Head;
			Head = Head->Next;
			delete pTemp;
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
	void insertFromFile(string name) {
		ifstream fin;
		fin.open(name);
		if (fin.fail()) cout << "ERROR opening file";
		int s;
		while (fin >> s)
		{
			insert(s);
		}
		fin.close();
	}
	void saveToFile(string name) {
		ofstream fout;
		fout.open(name, ios::out);
		if (fout.fail()) cout << "ERROR opening file";
		if (Head)
		{
			Node* temp = Head;
			do
			{
				fout << temp->number << endl;
				temp = temp->Next;
			} while (temp != Tail->Next);
		}
	}
	void del(int num) {
		if (num > 0 && num <= count)
		{
			if (num == 1)
			{
				Node* temp = Head;
				Head = Head->Next;
				delete temp;
				count--;
			}
			else if (num == count)
			{
				Node* temp = Tail;
				Tail->Prev->Next = Head;
				Head->Prev = Tail->Prev;
				Tail = Tail->Prev;
				delete temp;
				count--;
			}
			else
			{
				Node* temp = Head;
				for (int i = 1; i <= count; i++)
				{
					if (num == i)
					{
						temp->Prev->Next = temp->Next;
						temp->Next->Prev = temp->Prev;
						count--;
						break;
					}
					temp = temp->Next;
				}
				delete temp;
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
		if (num <= count && num > 0)
		{
			Node* temp1 = Head;
			Node* temp2 = temp1->Next;
			if (num == 1)
			{
				temp1 = Head->Next;
				Head->Next = Head->Next->Next;
				Head->Next->Prev = Head;
				temp1->Next = Head;
				Head->Prev = temp1;
				Head = temp1;
			}
			else if (num == count)
			{
				temp1 = Head; temp2 = Tail;
				temp2->Next = temp1->Next;
				temp1->Next->Prev = temp2;
				temp2->Prev->Next = temp1;
				temp1->Prev = temp2->Prev;
				Head = temp2;
				Head->Prev = NULL;
				Tail = temp1;
				Tail->Next = NULL;
			}
			else
			{
				for (int i = 1; i < count; i++)
				{
					if (i == num)
					{
						if (temp1->Next == Tail)
						{
							Tail->Prev = temp1->Prev;
							temp1->Prev->Next = Tail;
							Tail->Next = temp1;
							temp1->Prev = Tail;
							temp1->Next = NULL;
							Tail = temp1;

						}
						else
						{
							temp1->Prev->Next = temp2;
							temp2->Prev = temp1->Prev;
							temp2->Next->Prev = temp1;
							temp1->Next = temp2->Next;
							temp1->Prev = temp2;
							temp2->Next = temp1;
						}
					}
					temp1 = temp1->Next;
				}
			}
		}
	}
	void combine(List list) {
		Node* tmp = list.Head;
		while (tmp)
		{
			insert(tmp->number);
			tmp = tmp->Next;
		}
		delete tmp;
	}
	void showForward() {
		if (Head)
		{
			Node* temp = Head;
			do
			{
				cout << temp->number << endl;
				temp = temp->Next;
			} while (temp != Tail->Next);
			cout << "Amount is: " << count << endl;
		}
		else
		{
			cout << "Empty" << endl;
		}
	}
	void showBackward() {
		if (Head)
		{
			Node* temp = Tail;
			do
			{
				cout << temp->number << endl;
				temp = temp->Prev;
			} while (temp != Head->Prev);
			cout << "Amount is: " << count << endl;
		}
		else
		{
			cout << "Empty" << endl;
		}
	}
};
