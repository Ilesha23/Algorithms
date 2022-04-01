#pragma once
#include <vector>
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
	void addByName(Node* node) {
		Node* temp = new Node(node->name, node->number, node->group);
		Node* ptr, * ptr1;
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
	void showForward(Node* n) {
		if (n != 0)
		{
			tabs++;
			showForward(n->Right);
			for (int i = 0; i < tabs; i++) cout << "	";
			cout << n->number << " " << n->group << " " << n->name << endl;
			showForward(n->Left);
			tabs--;
		}
	}
	void showF(Node* n) {
		if (n != 0)
		{
			cout << n->number << " " << n->group << " " << n->name << endl;// n->name << " " << n->number << " " << n->group << endl;
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
			cout << n->number << endl;// n->name << " " << n->number << " " << n->group << endl;
		}
	}
	void showSymmetrically(Node* n) {
		if (n != 0)
		{
			showSymmetrically(n->Left);
			for (int i = 0; i < tabs; i++) cout << "	";
			cout << n->number << endl;// n->name << " " << n->number << " " << n->group << endl;
			showSymmetrically(n->Right);
		}
	}
	void show() {
		showForward(Root);
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
		//tree.addByName(mas[mas.size() / 2]);
		//mas.erase(mas.begin() + mas.size() / 2); // for rand
		for (int i = 0; i < mas.size(); i++)
		{
			tree.addByName(mas[i]);
		}
		delTree();
		*this = tree;
	}
};