#pragma once
#include <iostream>
#include <list>
using namespace std;

struct nodelinear {
	int key;
	string value;
};

class HashTableLinear
{
private:
	nodelinear* table[10];
	int numOfElements = 0;
	int numOfCollisions = 0;
	int hash(string key);

public:
	HashTableLinear();
	bool isempty();
	void insert(string v);
	void remove(string v);
	void print();
	void collisionRate();
};


