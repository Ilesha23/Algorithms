#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	HashTable ht(11);

	ht.AddL(49);
	ht.AddL(32);
	ht.AddL(75);
	ht.AddL(53);
	ht.AddL(85);
	ht.AddL(19);
	ht.AddL(76);
	ht.AddL(44);
	ht.AddL(5);
	
	ht.AddL(81);
	ht.AddL(82);
	ht.AddL(83);
	ht.AddL(84);
	ht.AddL(85);

	/*ht.Add(49);
	ht.Add(32);
	ht.Add(75);
	ht.Add(53);
	ht.Add(85);
	ht.Add(19);
	ht.Add(76);
	ht.Add(44);
	ht.Add(5);

	ht.Add(81);
	ht.Add(82);
	ht.Add(83);
	ht.Add(84);
	ht.Add(85);*/

	/*ht.Add2(49);
	ht.Add2(32);
	ht.Add2(75);
	ht.Add2(53);
	ht.Add2(85);
	ht.Add2(19);
	ht.Add2(76);
	ht.Add2(44);
	ht.Add2(5);

	ht.Add2(81);
	ht.Add2(82);
	ht.Add2(83);
	ht.Add2(84);
	ht.Add2(85);*/

	/*ht.Add3(49);
	ht.Add3(33);
	ht.Add3(75);
	ht.Add3(53);
	ht.Add3(85);
	ht.Add3(19);
	ht.Add3(76);
	ht.Add3(44);
	ht.Add3(5);

	ht.Add3(81);
	ht.Add3(82);
	ht.Add3(83);
	ht.Add3(84);
	ht.Add3(85);*/

	ht.Print();
	//ht.SearchL(19);
}