#include <iostream>
#include <string>
#include <cstring>
#include <cstddef>
#include <cmath>
#include <vector>


/// example hash-table (OPEN_ADDRESSING)
#define HASH_TABLE_SIZE 50

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



    Node *table[HASH_TABLE_SIZE];

public:
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
///

int main()
{
    HashTable<Person> newTable;

    /*Person *p1 = new Person("Artyom", "Devyatov", 20);
    Person *p2 = new Person("Vasya", "Petrov", 23);
    Person *p3 = new Person("Ilja", "Saveljev", 28);
    Person *p4 = new Person("Ilaj", "Savanna", 43);
    Person *p5 = new Person("Dmitry", "Kuzychev", 31);

    newTable.insert(p1);
    newTable.insert(p2);
    newTable.insert(p3);
    newTable.insert(p4); // have collisions  with Ilja
    newTable.insert(p5);


    Person search = newTable.find("Ilja");

    newTable.print();
    //cout<<search.surname<<"\t"<<search.name<<"\t"<<search.age;*/

    Person *p;
    for(int i = 0; i < 50; i++)
    {
        p = new Person(randString(2,10), "test", 10);
        newTable.insert(p);
    }

    newTable.print();
    return 0;
}














