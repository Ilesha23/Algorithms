#pragma once
#include <fstream>
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
		temp = NULL;
		delete temp;
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
			temp = NULL;
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
				temp = NULL;
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
						temp = NULL;
						delete temp;
						break;
					}
					temp2 = temp2->Next;
				}
				temp2 = NULL;
				delete temp2;
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					if (n - 1 == i)
					{
						Node* temp2 = temp->Next;
						temp->Next = temp->Next->Next;
						temp2 = NULL;
						delete temp2;
						break;
					}
					temp = temp->Next;
				}
				temp = NULL;
				delete temp;
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
				q++;
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
		temp1 = q.Head;
		Node* temp2 = Head;
		while (temp1 != q.Tail->Next)
		{
			temp2->data = temp1->data;
			temp2 = temp2->Next;
			temp1 = temp1->Next;
		}
		temp1 = temp2 = NULL;
		delete temp1, temp2;
	}
	void showStar() {
		int i = 0;
		Node* temp = Head;
		if (count % 2 == 0)
		{
			while (temp != Tail->Next)
			{
				if (count / 2 == i)
				{
					cout << "*" << endl;
				}
				cout << temp->data << endl;
				temp = temp->Next;
				i++;
			}
			cout << "Amount: " << count << endl;
		}
		else
		{
			while (temp != Tail->Next)
			{
				if (count / 2 == i)
				{
					cout << "*" << endl;
				}
				cout << temp->data << endl;
				temp = temp->Next;
				i++;
			}
			cout << "Amount: " << count << endl;
		}
		temp = NULL;
		delete temp;
	}
	Node* findMax() {
		Node* temp = Head;
		Node* max = temp;
		while (temp != Tail->Next)
		{
			if (temp->data > max->data)
			{
				max = temp;
			}
			temp = temp->Next;
		}
		temp = NULL;
		delete temp;
		
		return max;
	}
	Node* findMin() {
		Node* temp = Head;
		Node* min = temp;
		while (temp != Tail->Next)
		{
			if (temp->data < min->data)
			{
				min = temp;
			}
			temp = temp->Next;
		}
		temp = NULL;
		delete temp;

		return min;
	}
	void insertZeroAfterMax() {
		Node* zero = new Node;
		zero->data = 0;
		zero->Next = findMax()->Next;
		findMax()->Next = zero;
		count++;
	}
	Node* getByNum(int a) {
		if (a < count)
		{
			Node* temp = Head;
			int i = 0;
			while (temp != nullptr)
			{
				if (a == i)
				{
					return temp;
				}
				temp = temp->Next;
				i++;
			}
		}
	}
	void deleteMin() {
		Node* temp = Head;
		if (findMin() == Head)
		{
			Head = Head->Next;
		}
		else if (findMin() == Tail)
		{
			getByNum(count - 2)->Next = Tail = NULL;
			Tail = getByNum(count - 2);
		}
		else
		{
			Node* min = findMin();
			while (temp)
			{
				if (temp->Next == min)
				{
					temp->Next = min->Next;
					min = nullptr;
					delete min;
					break;
				}
				temp = temp->Next;
			}
		}
		count--;
		temp = NULL;
		delete temp;
	}
	void deleteAllButFirst() {
		for (int i = 1; i < count;)
		{
			pop(i);
		}
	}
	void deleteAllButLast() {
		Node* temp = Head;
		while (temp != Tail)
		{
			temp = temp->Next;
			pop();
		}
		temp = nullptr;
		delete temp;
	}
	void saveToFile(string name) {
		ofstream fout;
		fout.open(name, ios::out);
		if (fout.fail()) cout << "ERROR opening file";
		if (Head)
		{
			Node* temp = Tail;
			int a = count - 1;
			do
			{
				temp = getByNum(a);
				fout << temp->data << endl;
				a--;
			} while (a >= 0);
		}
	}
	void insertFromFile(string name) {
		ifstream fin;
		fin.open(name);
		if (fin.fail()) cout << "ERROR opening file";
		int s;
		popAll();
		while (fin >> s)
		{
			push(s);
		}
		fin.close();
	}
	void show() {
		Node* temp = Head;
		if (count < 1)
		{
			cout << "Empty" << endl;
		}
		else
		{
			while (temp != Tail->Next)
			{
				cout << temp->data << endl;
				temp = temp->Next;
			}
		}
		cout << "Amount: " << count << endl;
		temp = NULL;
		delete temp;
	}
};