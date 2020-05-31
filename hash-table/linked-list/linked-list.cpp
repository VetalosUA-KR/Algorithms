#include <iostream>
#include <string>
#include <cstring>
#include <cstddef>
#include <cmath>
#include <vector>
#include <ctime>

#define HASH_TABLE_SIZE 1000

using namespace std;

class Person // test class
{
public:
    string key;
    string surname;
    int age;

    Person()
    {
        this->key = "null";
        this->surname = "null";
        this->age = 0;
    }

    Person (string key, string surname, int age = 0)
    {
        this->key = key;
        this->surname = surname;
        this->age = age;
    }

};

template<typename T>
class HashTable
{
    struct Node
    {
        vector<T> List;
        string key = "free";
    };
public:
    Node *table[HASH_TABLE_SIZE];
    int hashTableSize = 0;

    HashTable()
    {
        for ( int i = 0; i < HASH_TABLE_SIZE; i++ )
        {
            table[i] = new Node();
        }
    }
    ~HashTable()
    {
        for ( int i = 0; i < HASH_TABLE_SIZE; i++ )
        {
            delete table[i];
        }
    }
    void print()
    {
        cout<<endl;
        for(int i = 0; i < HASH_TABLE_SIZE; i++)
        {
            if(table[i]->key == "free")
            {
                cout<<"free"<<endl;
            }
            else
            {
            auto iter = table[i]->List.begin();
            while(iter != table[i]->List.end())
            {
                cout<<"("<<iter->key<<":"<<iter->surname<<":"<<iter->age<<") -> ";
                ++iter;
            }
            cout<<endl;
            }
        }
    }
    int hashModul ( string str)
    {
        const int p = 31;
        long long hash_number = 0;
        long long p_pow = 1;
        for(size_t i = 0; i < str.length(); i++)
        {
            hash_number += (str[i] - 'a'+1) * p_pow;
            p_pow *= p;
        }
        return hash_number % HASH_TABLE_SIZE;
    }
    /// add element
    void insert (T *data)
    {
        long long hashNumber = hashModul(data->key);
        table[hashNumber]->List.push_back(*data);
        table[hashNumber]->key = "busy";
        hashTableSize++;
        return;
    }
    /// Find element by key
    T find (string key)
    {
        int hashNumber = hashModul(key);
        if(table[hashNumber]->key == "free")
        {
            Person result = table[hashNumber]->List.back();
            return result;
        }
        else
        {
            auto iter = table[hashNumber]->List.begin();
            while(iter->key !=  key)
            {
                ++iter;
            }
            return *iter;
        }
    }
    /// Delete element by key
    void deleteElement (string key)
    {
        int hashNumber = hashModul(key);
        int index = 0;
        auto iter = table[hashNumber]->List.begin();
        while(iter->key !=  key)
        {
            ++iter;
            index++;
        }
        table[hashNumber]->List.erase(table[hashNumber]->List.begin()+index);
        if(table[hashNumber]->List.empty())
        {
            table[hashNumber]->key = "free";
        }
    }
};
/// other functions
string randString(int min, int max)
{
    string str;
    int ran = min + rand() % (max - min);
    for(int i = 0; i < ran; i++)
    {
        str += char(rand() % 25 +97);
    }
    return str;
}
template <typename T>
int dlugListy(HashTable<T> *ht)
{
    int ma = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(ma < ht->table[i]->List.size())
        {
            ma = ht->table[i]->List.size();
        }
    }
    return ma;
}
/// /////////////////////////////////////////////////
int main()
{
    /// Kod do testowania
    srand( time(0) );
    HashTable<Person> newTable;

    Person * p = new Person("vitalii", "test", 10);
    Person * p2 = new Person("vetal", "test", 10);
    newTable.insert(p);
    newTable.insert(p2);
    newTable.print();


    return 0;
}

