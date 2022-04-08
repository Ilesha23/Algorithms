#pragma once
#include <vector>
#include <windows.h>
#include <fstream>
using namespace std;

struct Node {
	Node* Left, * Right, * Parent;
	int number, group;
	string name;
	Node(string s, int num, int g) {
		name = s;
		number = num;
		group = g;
		Left = Right = Parent = nullptr;
	}
	Node(){}
};

class Tree {
public:
	Node* Root;
	int count, tabs;
	Tree() {
		Root = nullptr;
		count = tabs =0;
	}
	void add(string n, int num, int g) {
		Node* temp = new Node(n, num, g);
		Node* ptr,* ptr1;
		ptr = ptr1 = Root;
		while (ptr != 0)
		{
			ptr1 = ptr;
			if (temp->name < ptr->name)
			{
				ptr = ptr->Left;
			}
			else
			{
				ptr = ptr->Right;
			}
		}
		temp->Parent = ptr1;
		if (ptr1 == 0)
		{
			Root = temp;
		}
		else
		{
			if (temp->name < ptr1->name)
			{
				ptr1->Left = temp;
			}
			else
			{
				ptr1->Right = temp;
			}
		}
		count++;
	}
	void addByNum(Node* node) {
		Node* temp = new Node(node->name, node->number, node->group);
		Node* ptr, * ptr1;
		ptr = ptr1 = Root;
		while (ptr != 0)
		{
			ptr1 = ptr;
			if (temp->number < ptr->number)
			{
				ptr = ptr->Left;
			}
			else
			{
				ptr = ptr->Right;
			}
		}
		temp->Parent = ptr1;
		if (ptr1 == 0)
		{
			Root = temp;
		}
		else
		{
			if (temp->number < ptr1->number)
			{
				ptr1->Left = temp;
			}
			else
			{
				ptr1->Right = temp;
			}
		}
		count++;
	}
	void addByN(string name, int num, int g) {
		Node* n = new Node(name, num, g);
		addByNum(n);
	}

	void showForward(Node* n) {
		if (n != 0)
		{
			tabs++;
			showForward(n->Right);
			for (int i = 0; i < tabs; i++) cout << "	";
			cout << n->name << " " << n->number << " " << n->group << endl;
			showForward(n->Left);
			tabs--;
		}
	}
	void showF(Node* n) {
		if (n != 0)
		{
			cout << n->name << " " << n->number << " " << n->group << endl;
			showF(n->Left);
			showF(n->Right);
		}
	}
	void showBackward(Node* n) {
		if (n != 0)
		{
			showBackward(n->Right);
			showBackward(n->Left);
			for (int i = 0; i < tabs; i++) cout << "	";
			cout << n->name << " " << n->number << " " << n->group << endl;
		}
	}
	void showSymmetrically(Node* n) {
		if (n != 0)
		{
			showSymmetrically(n->Left);
			for (int i = 0; i < tabs; i++) cout << "	";
			cout << n->name << " " << n->number << " " << n->group << endl;
			showSymmetrically(n->Right);
		}
	}
	void show() {
		if (Root)
		{
			showForward(Root);
		}
		else
		{
			cout << "Empty" << endl;
		}
	}
	void showPreOrder() {
		if (Root)
			showF(Root);
		else
			cout << "Empty" << endl;
	}
	void showPostOrder() {
		if (Root)
			showBackward(Root);
		else
			cout << "Empty" << endl;
	}
	void showSymm() {
		if (Root)
			showSymmetrically(Root);
		else
			cout << "Empty" << endl;
	}

	void delLeft(Node* n) {
		if (n != 0)
		{
			delLeft(n->Left);
			delLeft(n->Right);
			n->Parent->Left = nullptr;
			n->Parent = 0;
			delete n;
			count--;
		}
	}
	void delLeftTree() {
		if (Root->Left != 0)
		{
			delLeft(Root->Left);
		}
	}
	void delRight(Node* n) {
		if (n != 0)
		{
			delRight(n->Right);
			delRight(n->Left);
			n->Parent->Right = nullptr;
			n->Parent = 0;
			delete n;
			count--;
		}
	}
	void delRightTree() {
		if (Root->Right != 0)
		{
			delRight(Root->Right);
		}
	}
	void delTree() {
		delLeftTree();
		delRightTree();
		Root = nullptr;
		delete Root;
		count--;
	}

	void makeVectorFromTree(Node* n, vector<Node*>& m) {
		if (n != 0)
		{
			m.push_back(n);
			makeVectorFromTree(n->Left, m);
			makeVectorFromTree(n->Right, m);
		}
	}
	void remake() {
		Tree tree;
		vector<Node*> mas;
		makeVectorFromTree(Root, mas);
		//tree.addByNum(mas[mas.size() / 2]);
		//mas.erase(mas.begin() + mas.size() / 2); // for rand
		for (int i = 0; i < mas.size(); i++)
		{
			tree.addByNum(mas[i]);
		}
		delTree();
		*this = tree;
	}

	void save(Node* n, string name) {
		if (n != 0)
		{
			ofstream fout;
			if (fout.fail()) cout << "ERROR opening file";
			fout.open(name, ios::app);
			fout << n->number << endl << n->group << endl << n->name << endl;
			fout.close();
			save(n->Left, name);
			save(n->Right, name);
		}
	}
	void saveToFile(string name) {
		ofstream fout;
		if (fout.fail()) cout << "ERROR opening file";
		fout.open(name, ios::out);
		fout.close();
		save(Root, name);
	}
	void read(Node* n, string name) {
		ifstream fin;
		fin.open(name);
		if (fin.fail()) cout << "ERROR opening file";
		char buf[255];
		int num, g, i = 1;
		string nam;
		while (fin)
		{
			fin.getline(buf, 255);
			if (i % 3 == 1)
			{
				g = atoi(buf);
				i++;
			}
			else if (i % 3 == 2)
			{
				num = atoi(buf);
				i++;
			}
			else
			{
				nam = string(buf);
				i++;
				add(nam, num, g);
			}
		}
		fin.close();
	}
	void readFromFile(string name) {
		read(Root, name);
	}
};


//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(hConsole, 2);