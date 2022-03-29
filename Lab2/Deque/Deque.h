#pragma once
#include <fstream>
using namespace std;

struct Node {
	Node* Next, * Prev;
	int data;
};

class Deque {
private:
	
public:
	Node* Head, * Tail;
	int count;
	Deque() {
		Head = Tail = nullptr;
		count = 0;
	}
	void push_back(int x) {
		Node* temp = new Node;
		temp->data = x;
		if (Head)
		{
			temp->Prev = Tail;
			temp->Next = nullptr;
			Tail->Next = temp;
			Tail = temp;
		}
		else
		{
			Head = Tail = temp;
		}
		count++;
		temp = nullptr;
		delete temp;
	}
	void push_front(int x) {
		Node* temp = new Node;
		temp->data = x;
		if (Head)
		{
			temp->Next = Head;
			Head->Prev = temp;
			temp->Prev = nullptr;
			Head = temp;
		}
		else
		{
			Head = Tail = temp;
		}
		count++;
		temp = nullptr;
		delete temp;
	}
	void pop_front() {
		Node* temp = Head;
		if (Head != Tail)
		{
			Head = Head->Next;
		}
		else
		{
			Head = Tail = nullptr;
		}
		temp = nullptr;
		delete temp;
		count--;
	}
	void pop_back() {
		Node* temp = Tail;
		if (Head != Tail)
		{
			Tail = Tail->Prev;
		}
		else
		{
			Head = Tail = nullptr;
		}
		temp = nullptr;
		delete temp;
		count--;
	}
	void popAll() {
		while (Head)
		{
			pop_front();
		}
	}
	int getFront() {
		return Head->data;
	}
	int getBack() {
		return Tail->data;
	}
	int get(int x) {
		if (x < count)
		{
			Node* temp = Head;
			int i = 0;
			while (temp != Tail->Next)
			{
				if (x == i)
				{
					return temp->data;
				}
				i++;
				temp = temp->Next;
			}
		}
	}
	bool isEmpty() {
		if (Head)
		{
			return false;
		}
		else
		{
			return true;
		}
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
				fout << temp->data << endl;
				temp = temp->Next;
			} while (temp != Tail->Next);
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
			push_back(s);
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
		temp = nullptr;
		delete temp;
	}
};
