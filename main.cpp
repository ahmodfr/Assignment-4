#include <iostream>
#include "HashTableChaining.h"
#include "HashTableLinear.h"
#include "Employee"
#include <list>
using namespace std;

int main()
{
	
	cout << "This is the table using chaining " << endl;
	HashTableChaining tableChain;

	
	tableChain.insert("Mina");
	tableChain.insert("Fawzy");
	tableChain.insert("Yara");
	tableChain.insert("Mariam");
	tableChain.insert("Ayman");
	tableChain.insert("Roshdy");
	tableChain.insert("Aya");
	tableChain.insert("Abdallah");
	tableChain.insert("Fatma");



	tableChain.print();
	cout << endl;
	cout << "Rate of collision is ";
	tableChain.collisionRate();
	cout << "-----------------------------------------------------------------" << endl;
	cout << "table after calling the remove function to Yara" << endl;
	tableChain.remove("Yara");
	tableChain.print();
	cout << "--------------------------------------------------------------------" << endl << endl;


	cout << "This is the table using linear proping" << endl << endl;

	HashTableLinear tableLinear;
    tableLinear.insert("Mina");
	tableLinear.insert("Fawzy");
	tableLinear.insert("Yara");
	tableLinear.insert("Mariam");
	tableLinear.insert("Ayman");
	tableLinear.insert("Roshdy");
	tableLinear.insert("Aya");
	tableLinear.insert("Abdallah");
	tableLinear.insert("Fatma");

	tableLinear.print();

	cout << endl;
	cout << "Rate of collision is "; 
	tableLinear.collisionRate();
	cout << "-----------------------------------------------------------------" << endl;
	cout << "table after calling the remove function to Yara" << endl;
	tableLinear.remove("Yara");
	tableLinear.print();

	return 0;
}

