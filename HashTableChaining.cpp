#include <iostream>
#include <list>
#include "HashTableChaining.h"
using namespace std;



int HashTableChaining::hash(string key)
{
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum = sum + key[i];
    }
   
    return sum%10;
}

HashTableChaining::HashTableChaining()
{
    for (int i = 0; i < 10; i++) {
        table[i] = NULL;
    }
}

bool HashTableChaining::isempty()
{
    int index= 0;
    for (int i = 0; i < 10; i++) {

        if (table[index] = NULL) {
            index++;
        }
    }
    if (index == numOfElements)
        return true;
    
    return false;
}

void HashTableChaining::insert(string v)
{
    node* node1=new node;
    node1->value = v;
    node1->next = NULL;

    int index = hash(v);

    if (table[index] == NULL) {
        table[index] = node1;
        numOfElements++;
        return;
    }
    else {
        node* p = table[index];
        while (p->next != NULL)
            p = p->next;

        p->next = node1;
        numOfElements++;
        numOfCollisions++;
    }

}

void HashTableChaining::remove(string v)
{
    int index = hash(v);

    if (table[index] == NULL) {
        cout << "Value does not exist" << endl;
    }
    else if (table[index]->value == v) {
        node* p = table[index];
        table[index] = table[index]->next;
        delete p;
        numOfElements--;
    }
    else
    {
        node* p1 = table[index];
        node* p2 = table[index];

        while (p2->value != v)
        {
            p1 = p2;
            p2 = p2->next;
        }
        if (p2 == NULL)
            cout << "Value does not exist" << endl;
        else
        {
            p1->next = p2->next;
            delete p2;
            numOfElements--;
        }
    }

}

void HashTableChaining::print()
{
    if (HashTableChaining::isempty())
        cout << "This table is empty" << endl;

    for (int i = 0; i < 10; i++) {
        if (table[i] != NULL) {
            node* p = table[i];
            cout << i << " : ";
            while (p != NULL) {
                cout << p->value << " ---> ";
                p = p->next;
            }
            cout << endl;
        }
        else {
            cout << i << " : " << " ";
            cout << endl;
        }
    }
}

void HashTableChaining::collisionRate()
{

    cout << endl;
 /*   cout << "Number of collisions is " << numOfCollisions << endl;

    cout << "Number of elements is " << numOfElements << endl;*/

    double rate = 0;
    rate = ((double)numOfCollisions / numOfElements)*100;
    cout << rate << "%" << endl;
}

