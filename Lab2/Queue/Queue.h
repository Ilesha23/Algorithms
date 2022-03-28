#pragma once
using namespace std;

struct Node {
	Node* Next,* Prev;
	int data;
};

class Queue {
private:
	Node* Head, * Tail;
public:
	int count;
	Queue() {
		Head = Tail = nullptr;
		count = 0;
	}
	void push(int x) {
		Node* temp = new Node;
		temp->data = x;
		if (Head)
		{
			Tail->Next = temp;
			temp->Prev = Tail;
			Tail = Tail->Next;
			Tail->Prev = temp->Prev;
		}
		else
		{
			Head = Tail = temp;
		}
		count++;
		temp = nullptr;
		delete temp;
	}
	void pop() {
		Node* temp = Head;
		Head = Head->Next;
		temp = nullptr;
		delete temp;
		count--;
	}
	void popAll() {
		while (Head)
		{
			pop();
		}
	}
	int getElem() {
		return Head->data;
	}
	double average() {
		double sum = 0;
		Node* temp = Head;
		while (temp != Tail->Next)
		{
			sum += temp->data;
			temp = temp->Next;
		}
		temp = nullptr;
		delete temp;
		return sum / count;
	}
	Node* findMin() {
		Node* temp = Head;
		Node* min = temp;
		//min->data = Head->data;
		while (temp != Tail->Next)
		{
			if (min->data > temp->data)
			{
				min = temp;
			}
			temp = temp->Next;
		}
		temp = nullptr;
		delete temp;
		return min;
	}
	Node* findMax() {
		Node* temp = Head;
		Node* max = new Node;
		max->data = Head->data;
		while (temp != Tail->Next)
		{
			if (max->data < temp->data)
			{
				max = temp;
			}
			temp = temp->Next;
		}
		temp = nullptr;
		delete temp;
		return max;
	}
	void showBeforeMin() {
		if (findMin() == Head)
		{
			cout << "Empty" << endl;
		}
		else
		{
			cout << findMin()->Prev->data << endl;
		}
	}
	void show() {
		Node* temp = Head;
		while (temp != Tail->Next)
		{
			cout << temp->data << endl;
			temp = temp->Next;
		}
		cout << "Amount: " << count << endl;
		temp = nullptr;
		delete temp;
	}
};