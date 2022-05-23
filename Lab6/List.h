#pragma once
#include <iostream>
#include <fstream>
#include "stdio.h"
#include <cstddef>
#include "HashTable.h"
using namespace std;

struct Node
{
	Node* Prev, * Next;
	int number;
};
//struct N
//{
//	N* Prev, * Next;
//	HTElem data;
//};

class List {
public:Node* Head, * Tail;
	  //N* H, * T;
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
		while (Head != Tail)
		{
			Node* temp = Head;
			Head = Head->Next;
			delete temp;
		}
		Tail = Head = NULL;
		count = 0;
	}
	void insert(int x) {
		Node* temp = new Node;
		temp->number = x;
		if (Head)
		{
			temp->Prev = Tail; 
			temp->Next = Head; 
			Tail->Next = temp;
			Tail = temp;
			Head->Prev = temp;
		}
		else
		{
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
			} while (temp != Head);
		}
	}
	void del(int num) {
		if (num > 0 && num <= count)
		{
			if (num == 1)
			{
				Node* temp = Head;
				Tail->Next = Head->Next;
				Head->Next->Prev = Tail;
				Head = Tail->Next;
				delete temp;
				count--;
			}
			else if (num == count)
			{
				Node* temp = Tail;
				Head->Prev = Tail->Prev;
				Tail->Prev->Next = Head;
				Tail = Head->Prev;
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
		if (num <= count && num > 0)
		{
			Node* temp1 = Head;
			Node* temp2 = Head;
			if (num == 1)
			{
				int a = Head->number;
				Head->number = Head->Next->number;
				Head->Next->number = a;
			}
			else if (num == count)
			{
				int a = Head->number;
				Head->number = Tail->number;
				Tail->number = a;
			}
			else
			{
				Node* tmp = Head->Next;
				for (int i = 2; i < count; i++)
				{
					if (num == i)
					{
						int a = tmp->number;
						tmp->number = tmp->Next->number;
						tmp->Next->number = a;
					}
					tmp = tmp->Next;
				}
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
				Tail->Next = Head->Next;
				Head->Next->Prev = Tail;
				Head->Prev = Head->Next;
				Head->Next = Head->Next->Next;
				Head->Prev->Next = Head;
				Head->Next->Prev = Head;
				Head = Head->Prev;
			}
			else if (num == count)
			{
				Tail->Prev->Next = Head;
				Head->Prev = Tail->Prev;
				Tail->Prev = Head;
				Tail->Next = Head->Next;
				Head->Next = Tail;
				Tail->Next->Prev = Tail;
				Head = Tail;
				Tail = Head;
			}
			else
			{
				Node* temp1 = Head->Next;
				Node* temp2 = temp1->Next;
				for (int i = 2; i < count; i++)
				{
					if (i == num)
					{
						temp1->Prev->Next = temp2;
						temp2->Prev = temp1->Prev;
						temp2->Next->Prev = temp1;
						temp1->Next = temp2->Next;
						temp1->Prev = temp2;
						temp2->Next = temp1;
					}
					temp1 = temp1->Next;
				}
			}
		}
	}
	void combine(List list) {
		Node* tmp = list.Head;
		for (int i = 0; i < list.count; i++)
		{
			insert(tmp->number);
			if (tmp->Next != list.Head)
			{
				tmp = tmp->Next;
			}
		}
	}
	void showForward() {
		if (Head)
		{
			Node* temp = Head;
			do
			{
				cout << temp->number << endl;
				temp = temp->Next;
			} while (temp != Head);
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
			} while (temp != Tail);
			cout << "Amount is: " << count << endl;
		}
		else
		{
			cout << "Empty" << endl;
		}
	}


	/*void delAllList()
	{
		while (Head != Tail)
		{
			N* temp = H;
			H = H->Next;
			delete temp;
		}
		T = H = NULL;
		count = 0;
	}
	void ins(HTElem& x) {
		N* temp = new N;
		temp->data = x;
		if (H)
		{
			temp->Prev = T;
			temp->Next = H;
			T->Next = temp;
			T = temp;
			H->Prev = temp;
		}
		else
		{
			H = T = temp;
		}
		count++;
	}*/
	/*void del(int num) {
		if (num > 0 && num <= count)
		{
			if (num == 1)
			{
				N* temp = H;
				T->Next = H->Next;
				H->Next->Prev = T;
				H = T->Next;
				delete temp;
				count--;
			}
			else if (num == count)
			{
				N* temp = T;
				H->Prev = T->Prev;
				T->Prev->Next = H;
				T = H->Prev;
				delete temp;
				count--;
			}
			else
			{
				N* temp = H;
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
	void showForward() {
		if (H)
		{
			N* temp = H;
			do
			{
				cout << temp->data.data << endl;
				temp = temp->Next;
			} while (temp != H);
			cout << "Amount is: " << count << endl;
		}
		else
		{
			cout << "Empty" << endl;
		}
	}*/
};
