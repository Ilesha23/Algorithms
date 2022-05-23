#pragma once
#include <vector>
#include <iomanip>
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
	vector<HTElem> arr2;
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
				n.contains = true;
				arr[i] = n;
				full++;
				break;
			}
		}
		if (!n.contains)
		{
			arr2.push_back(n);
		}
		if ((full * 100 / length) >= 70)
		{
			Resize();
		}
	}
	void Add2(int d) {
		HTElem n(hash(d), d, false);
		int h = hash(d);
		for (int i = h; i < length; i += i + 3 * i * i)
		{
			if (!arr[i].contains)
			{
				n.contains = true;
				arr[i] = n;
				full++;
				break;
			}
		}
		if (!n.contains)
		{
			arr2.push_back(n);
		}
		if ((full * 100 / length) >= 70)
		{
			Resize();
		}
	}
	void Add3(int d) {
		HTElem n(hash(d), d, false);
		int h = hash(d);
		for (int i = h; i < length; i *= hash(h))
		{
			if (!arr[i].contains)
			{
				n.contains = true;
				arr[i] = n;
				full++;
				break;
			}
		}
		if (!n.contains)
		{
			arr2.push_back(n);
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
	void Resize() {
		HashTable temp(length + 10);
		for (int i = 0; i < length; i++)
		{
			if (arr[i].contains)
			{
				temp.Add(arr[i].data);
			}
		}
		for (int i = 0; i < arr2.size(); i++)
		{
			temp.Add(arr2[i].data);
		}
		length += 10;
		arr = new HTElem[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = temp.arr[i];
		}
		temp = NULL;
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
		for (int i = 0; i < arr2.size(); i++)
		{
			temp.Add3(arr2[i].data);
		}
		length += 10;
		arr = new HTElem[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = temp.arr[i];
		}
		temp = NULL;
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
		/*for (int i = 0; i < arr2.size(); i++)
		{
			cout << arr2[i].data << " " << arr2[i].key << "    ";
		}*/
	}
};