#include "HashTableLinear.h"

int HashTableLinear::hash(string key)
{
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum = sum + key[i];
    }

    return sum % 10;
}

HashTableLinear::HashTableLinear()
{
    for (int i = 0; i < 10; i++) {
        table[i] = NULL;
    }

}

bool HashTableLinear::isempty()
{
    int index = 0;
    for (int i = 0; i < 10; i++) {

        if (table[index] = NULL) {
            index++;
        }
    }
    if (index == numOfElements)
        return true;

    return false;
}

void HashTableLinear::insert(string v)
{
    nodelinear* node1 = new nodelinear;
    node1->value = v;

    int index = hash(v);
    if (table[index] == NULL) {
        table[index] = node1;
        numOfElements++;
        return;
    }
    else {
        int i = index + 1;

        while (table[index]!=NULL) {
            
            index++;
            index = index % 10; // linear proping equation searches for the closest NULL node
        }
        if (table[index] == NULL) {
            table[index] = node1;
            numOfCollisions++;
            numOfElements++;
        }
    }
}

void HashTableLinear::remove(string v)
{
    int index = hash(v);
    while (table[index] != NULL) {
        if (table[index]->value == v) {
            table[index] = NULL;
            numOfElements--;
        }
        index++;
        index = index % 10;
    }
   /* if (table[index] == NULL)
        cout << "element doesn't exist" << endl;*/
}

void HashTableLinear::print()
{
    for (int i = 0; i < 10; i++) {
        if (table[i] != NULL) {
            cout << i << " : " << table[i]->value << endl;

        }
        else
            cout << i << " : " << " " << endl;

    }
}

void HashTableLinear::collisionRate()
{
    cout << endl;
    cout << ((double)numOfCollisions / numOfElements) * 100 << "%" << endl;
}
