#include <iostream>
#include <list>
#include <cstring>
using namespace std;
/**
 * Um array que ira armazenar uma lista que ira armazenar os pares
 * 
 * 
*/

class hashTable
{
private:
    static const int hashGroups = 10;
    list<pair<string,int>> table[hashGroups];
public:
    hashTable(/* args */);
    ~hashTable();
};

hashTable::hashTable(/* args */)
{
}

hashTable::~hashTable()
{
}
