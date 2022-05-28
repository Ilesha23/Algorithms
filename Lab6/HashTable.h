#pragma once
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

struct HTElem
{
	int key,
		data;
	vector<HTElem> list;
	bool contains;
	HTElem() {
		key = 0;
		data = 0;
		contains = false;
	}
	HTElem(int k, int d, bool i) {
		key = k;
		data = d;
		contains = i;
	}
};

class HashTable {
private:
	HTElem* arr;
	int length,
		full = 0;
public:
	HashTable(int size) {
		length = size;
		arr = new HTElem[length];
	}
 	int hash(double k) {
		double a = (sqrt(5) - 1) / 2;
		double c = (k * a);
		return fmod(c, 1) * length;
	}
	/*int hash(double k) {
		return fmod(k, 9);
	}*/
	void Add(int d) {
		HTElem n(hash(d), d, false);
		int h = hash(d);
		for (int i = h; i < length; i++)
		{
			if (!arr[i].contains)
			{
				arr[i] = n;
				arr[i].contains = true;
				full++;
				break;
			}
		}
		Check();
	}
	void Add2(int key) {
		for (int i = 0; i < length; i++) {
			int hash = (key % length + 1 * i + 3 * i * i) % length;
			if (!arr[hash].contains) {
				arr[hash].data = key;
				arr[hash].key = hash;
				arr[hash].contains = true;
				full++;
				break;
			}
		}
		if ((full * 100 / length) >= 70)
		{
			Resize2();
		}
	}
	void Add3(int key) {
		for (int i = 0; length; i++) {
			int hash = (key % length + i * (1 + (key % (length - 1)))) % length;
			if (!arr[hash].contains) {
				arr[hash].data = key;
				arr[hash].key = hash;
				arr[hash].contains = true;
				full++;
				break;
			}
		}
		if ((full * 100 / length) >= 70)
		{
			Resize3();
		}
	}
	void AddL(int d) {
		HTElem n(hash(d), d, false);
		int h = hash(d);
		if (!arr[h].contains)
		{
			arr[h] = n;
			arr[h].contains = true;
			full++;
		}
		else
		{
			arr[h].list.push_back(n);
		}
	}
	void Search(int d) {
		int h = hash(d);
		if (arr[h].data == d)
		{
			cout << endl << setw(4) << arr[h].data << setw(4) << h << setw(4) << arr[h].key << "\t";
			return;
		}
		for (int i = h; i < length; i++)
		{
			if (arr[i].data == d)
			{
				cout << endl << setw(4) << arr[i].data << setw(4) << i << setw(4) << arr[i].key << "\t";
				return;
			}
		}
	}
	void Search2(int d) {
		for (int i = 0; i < length; i++)
		{
			int hash = (d % length + 1 * i + 3 * i * i) % length;
			if (arr[hash].data == d) {
				cout << endl << setw(4) << arr[hash].data << setw(4) << hash << setw(4) << arr[hash].key << "\t";
				break;
			}
		}
	}
	void Search3(int d) {
		for (int i = 0; i < length; i++)
		{
			int hash = (d % length + i * (1 + (d % (length - 1)))) % length;
			if (arr[hash].data == d) {
				cout << endl << setw(4) << arr[hash].data << setw(4) << hash << setw(4) << arr[hash].key << "\t";
				break;
			}
		}
	}
	void SearchL(int d) {
		int h = hash(d);
		if (arr[h].data == d)
		{
			cout << endl << setw(4) << arr[h].data << setw(4) << h << setw(4) << arr[h].key << "\t";
			return;
		}
		else
		{
			for (int i = 0; i < arr[h].list.size(); i++)
			{
				if (arr[h].list[i].data == d)
				{
					cout << endl << setw(4) << arr[h].data << setw(4) << h << setw(4) << arr[h].key << setw(4) << i << "\t";
					return;
				}
			}
		}
	}
	void Check() {
		if ((full * 100 / length) >= 70)
		{
			Resize();
		}
	}
	void Resize() {
		HashTable temp(length + 10);
		for (int i = 0; i < length; i++)
		{
			if (arr[i].contains)
			{
				temp.Add(arr[i].data);
			}
		}
		length += 10;
		arr = new HTElem[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = temp.arr[i];
		}
		temp = NULL;
	}
	void Resize2() {
		HashTable temp(length + 10);
		for (int i = 0; i < length; i++)
		{
			if (arr[i].contains)
			{
				temp.Add2(arr[i].data);
			}
		}
		/*for (int i = 0; i < arr2.size(); i++)
		{
			temp.Add2(arr2[i].data);
		}*/
		length += 10;
		arr = new HTElem[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = temp.arr[i];
		}
		temp = NULL;
		//arr2.clear();
	}
	void Resize3() {
		HashTable temp(length + 10);
		for (int i = 0; i < length; i++)
		{
			if (arr[i].contains)
			{
				temp.Add3(arr[i].data);
			}
		}
		/*for (int i = 0; i < arr2.size(); i++)
		{
			temp.Add3(arr2[i].data);
		}*/
		length += 10;
		arr = new HTElem[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = temp.arr[i];
		}
		temp = NULL;
	}
	void Insert() {
		ifstream in;
		in.open("1.txt");
		if (in.fail()) cout << "ERROR opening file";
		int d;
		while (in >> d)
		{
			Add(d);
		}
		in.close();
	}
	void Insert2() {
		ifstream in;
		in.open("1.txt");
		if (in.fail()) cout << "ERROR opening file";
		int d;
		while (in >> d)
		{
			Add2(d);
		}
		in.close();
	}
	void Insert3() {
		ifstream in;
		in.open("1.txt");
		if (in.fail()) cout << "ERROR opening file";
		int d;
		while (in >> d)
		{
			Add3(d);
		}
		in.close();
	}
	void InsertL() {
		ifstream in;
		in.open("1.txt");
		if (in.fail()) cout << "ERROR opening file";
		int d;
		while (in >> d)
		{
			AddL(d);
		}
		in.close();
	}
	void Delete(int d) {
		int h = hash(d);
		if (arr[h].data == d)
		{
			arr[h].data = NULL;
			arr[h].key = NULL;
			arr[h].contains = false;
			return;
		}
		for (int i = h; i < length; i++)
		{
			if (arr[i].data == d)
			{
				arr[i].data = NULL;
				arr[i].key = NULL;
				arr[i].contains = false;
				return;
			}
		}
	}
	void Delete2(int d) {
		for (int i = 0; i < length; i++)
		{
			int hash = (d % length + 1 * i + 3 * i * i) % length;
			if (arr[hash].data == d) {
				arr[hash].data = NULL;
				arr[hash].key = NULL;
				arr[hash].contains = false;
				break;
			}
		}
	}
	void Delete3(int d) {
		for (int i = 0; i < length; i++)
		{
			int hash = (d % length + i * (1 + (d % (length - 1)))) % length;
			if (arr[hash].data == d) {
				arr[hash].data = NULL;
				arr[hash].key = NULL;
				arr[hash].contains = false;
				break;
			}
		}
	}
	void DeleteL(int d) {
		int h = hash(d);
		if (arr[h].data == d)
		{
			arr[h].contains = false;
			for (int i = 0; i < arr[h].list.size(); i++)
			{
				AddL(arr[h].list[i].data);
			}
			if (arr[h].key != h)
			{
				arr[h].data = NULL;
				arr[h].key = NULL;
				arr[h].list.clear();
			}
			return;
		}
		else
		{
			for (int i = 0; i < arr[h].list.size(); i++)
			{
				if (arr[h].list[i].data == d)
				{
					arr[h].list[i].data = NULL;
					arr[h].list[i].key = NULL;
					arr[h].list[i].contains = false;
					return;
				}
			}
		}
	}
	void Print() {
		for (int i = 0; i < length; i++)
		{
			if (arr[i].contains)
			{
				cout << setw(4) << arr[i].data << setw(4) << i << setw(4) << arr[i].key << "\t";
				for (int j = 0; j < arr[i].list.size(); j++)
				{
					cout << setw(4) << arr[i].list.at(j).data << "  ";
				}
				cout << endl;
			}
			else
			{
				cout << "    " << setw(4) << i << "  " << endl;
			}
		}
		cout << endl;
	}
};