#pragma once
#include <iostream>
#include <list>
using namespace std;


struct node {
	int key;
	string value;
	node* next;
};
class HashTableChaining
{
private: 
	node* table[10];
	int numOfElements=0;
	int numOfCollisions=0;
	int hash(string key);

public:
	HashTableChaining();
	bool isempty();
	void insert(string v);
	void remove(string v);
	void print();
	void collisionRate();
};

