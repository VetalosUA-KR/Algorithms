#include <iostream>
#include <string>
#include <cstring>
#include <cstddef>
#include <cmath>


/// example hash-table (OPEN_ADDRESSING)
using namespace std;

unsigned long hashLine(string str, int proba, unsigned long size_H);

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
        this->key= key;
        this->surname = surname;
        this->age = age;
    }

};

template<typename T>
class HashTable
{
    struct Node
    {
        T value;
        string key = "free";
    };
    void insert2(T * data)
    {
        unsigned long hashNumber = hashLine(data->key, 1, HASH_TABLE_SIZE);
        if (table[hashNumber].key == "free")
        {
            table[hashNumber].value = *data;
            table[hashNumber].key = "busy";
            hashTableBusy++;
        }
        else
        {
            int proba = 1;
            while(hashNumber < HASH_TABLE_SIZE && table[hashNumber].key == "busy")
            {
                hashNumber = hashLine(data->key, proba, HASH_TABLE_SIZE);
                proba++;
            }
            table[hashNumber].value = *data;
            table[hashNumber].key = "busy";
            hashTableBusy++;
        }
    }

public:
    unsigned long int hashTableBusy = 0;

    unsigned long int HASH_TABLE_SIZE;
    Node *table;
    HashTable(unsigned long int hts)
    {
        cout<<"konstruktor"<<endl;
        HASH_TABLE_SIZE = hts;
        table = new Node[HASH_TABLE_SIZE];
        for ( int i = 0; i < HASH_TABLE_SIZE; i++ )
        {
            table[i] = Node();
        }
    }
    HashTable()
    {
        HASH_TABLE_SIZE = 1;
        table = new Node[HASH_TABLE_SIZE];
        for(int i = 0; i < HASH_TABLE_SIZE; i++)
        {
            table[i] = Node();
        }
    }
    /**
    Tutaj uzyto inne metoda do wstawienia elementow, dlatego ze, przy uzyciu zwyklej metody my uzywamy wskaznik na metodu haszowania (liniowa/kwadratowa/podwojne)
    tutaj uzywamy metody liniowej
    */
    HashTable & operator = ( HashTable & HT)
    {
        if(this == &HT) return *this;
        if(HT.wspHashTable() >= 0.5)
        {
            this->HASH_TABLE_SIZE = HT.HASH_TABLE_SIZE*2;
        }
        else if(HT.wspHashTable() <= 0.125)
        {
            this->HASH_TABLE_SIZE = HT.HASH_TABLE_SIZE/2;
        }
        else this->HASH_TABLE_SIZE = HT.HASH_TABLE_SIZE;

        table = new Node[HASH_TABLE_SIZE];
        for(int i = 0; i < HASH_TABLE_SIZE; i++)
        {
            table[i] = Node();
        }

        for(int i = 0; i < HT.HASH_TABLE_SIZE; i++)
        {
            if(HT.table[i].key == "busy")
            {
                this->insert2(&HT.table[i].value);
            }
        }

        return *this;
    }

    ~HashTable()
    {
        delete table;
    }
    void print()
    {
        cout<<endl;
        for(int i = 0; i < HASH_TABLE_SIZE; i++)
        {
            cout<<table[i].key<<" [ "<<table[i].value.key<<" ]"<<endl;
        }
    }

    /// add element
    void insert (T *data, unsigned long(*hashMetod)(string k, int p, unsigned long size_H))
    {
        unsigned long hashNumber = hashMetod(data->key, 1, HASH_TABLE_SIZE);
        if (table[hashNumber].key == "free")
        {
            table[hashNumber].value = *data;
            table[hashNumber].key = "busy";
            hashTableBusy++;
            return;
        }
        else
        {
            int proba = 1;
            while(hashNumber < HASH_TABLE_SIZE && table[hashNumber].key == "busy")
            {
                hashNumber = hashMetod(data->key, proba, HASH_TABLE_SIZE);
                proba++;
            }
            table[hashNumber].value = *data;
            table[hashNumber].key = "busy";
            hashTableBusy++;
        }
    }
    /// Find element by key
    T find ( string key, unsigned long(*hashMetod)(string key, int proba, unsigned long size_H))
    {
        unsigned long hashNumber = hashMetod (key, 1, HASH_TABLE_SIZE);
        Person result = table[hashNumber].value;
        if(table[hashNumber].value.key == key)
        {
            return result;
        }

        int proba = 1;
        while(hashNumber < HASH_TABLE_SIZE && table[hashNumber].key == "busy" && table[hashNumber].value.key != key)
        {
            hashNumber = hashMetod(key, proba, HASH_TABLE_SIZE);
            proba++;
        }
        result = table[hashNumber].value;
        try
        {
            if (result.key != key)
            {
                throw 1;
            }
            return result;
        }
        catch(int i)
        {
            cout << "Error - " << i << " not found person!!!!" << endl;
            return Person("NULL","NULL",0);
        }
    }
    /// Delete element by key
    void deleteElement ( string key, unsigned long(*hashMetod)(string key, int proba, unsigned long size_H))
    {
        unsigned long hashNumber = hashMetod (key, 1, HASH_TABLE_SIZE);
        Person result = table[hashNumber].value;
        if(table[hashNumber].value.key == key)
        {
            table[hashNumber].key = "free";
            hashTableBusy--;
            return;
        }

        int proba = 2;
        while(hashNumber < HASH_TABLE_SIZE && table[hashNumber].key == "busy" && table[hashNumber].value.key != key)
        {
            hashNumber = hashMetod(key, proba, HASH_TABLE_SIZE);
            proba++;
        }
        result = table[hashNumber].value;

        try
        {
            if (result.key != key)
            {
                throw 1;
            }
            table[hashNumber].key = "free";
            hashTableBusy--;
            return;
        }
        catch(int i)
        {
            cout << "Error - " << i << " not found person!!!!" << endl;
        }
    }

    float wspHashTable()
    {
        return (hashTableBusy*1.0)/(HASH_TABLE_SIZE*1.0);
    }
};

unsigned long int hash_djb2(string str, unsigned long size_H)
{
    unsigned long int hash;
    int c;
    hash = 5381;
    for(auto x: str)
    {
        c = x;
        hash = ((hash << 5) + hash) + c;
    }
    return (hash % size_H);
}

unsigned long hashModul ( string str, unsigned long size_H )
{
    const int p = 31;
    long long hash_number = 0;
    long long p_pow = 1;
    for(size_t i = 0; i < str.length(); i++)
    {
        hash_number += (str[i] - 'a'+1) * p_pow;
        p_pow *= p;
    }
    return hash_number % size_H;
}

unsigned long hashHalfModul ( string str, unsigned long size_H )
{
    const int p = 31;
    long long hash_number = 0;
    long long p_pow = 1;
    for(size_t i = 0; i < str.length()/2; i++)
    {
        hash_number += (str[i] - 'a'+1) * p_pow;
        p_pow *= p;
    }
    return hash_number % size_H;
}

unsigned long hashLine(string str, int proba, unsigned long size_H)
{
    unsigned long hash_number = hashModul(str, size_H)+proba;
    return hash_number % size_H;
}
unsigned long hashQuadratic(string str, int proba, unsigned long size_H)
{
    unsigned long hash_number = (hashModul(str, size_H)+ 3*proba + 2*pow(proba,2));
    return hash_number % size_H;
}
unsigned long hashDouble(string str, int proba, unsigned long size_H)
{
    unsigned long hash_number = hashModul(str, size_H) + proba*hashModul(str,size_H-proba);
    return hash_number % size_H;
}

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
    HashTable<Person> newTable(16);

    Person *p1 = new Person("Artyom", "Devyatov", 20);
    Person *p2 = new Person("Vasya", "Petrov", 23);
    Person *p3 = new Person("Ilja", "Saveljev", 28);
    Person *p4 = new Person("Ilaj", "Savanna", 43);
    Person *p5 = new Person("Dmitry", "Kuzychev", 31);

    newTable.insert(p1, hashLine);
    newTable.insert(p2, hashLine);
    newTable.insert(p3, hashLine);
    newTable.insert(p4, hashLine); // have collisions  with Ilja
    newTable.insert(p5, hashLine);

    //Person search = newTable.find("Ilaj", hashQuadratic);

    cout<<"[OLD]"<<endl;
    newTable.print();
    cout<<" [NEW] "<<endl;
    HashTable<Person> nt;

    nt = newTable;

    Person *p = new Person("Vitalii", "Voitenko", 26);
    nt.insert(p, hashLine);
    nt.insert(p, hashLine);
    nt.insert(p, hashLine);
    nt.print();
    ///cout<<newTable.wspHashTable()<<endl;




    return 0;
}














