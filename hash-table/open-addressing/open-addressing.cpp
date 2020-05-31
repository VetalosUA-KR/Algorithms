#include <iostream>
#include <string>
#include <cstring>
#include <cstddef>
#include <cmath>
#include <windows.h>
#include <ctime>

using namespace std;

void SetColor(int text, int background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

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
    operator = wykonuje funkcji przehaszowania, jesli wspolczynik tablicy jest wiekszy od 0.5 to przehaszujemy wszystkie elementy do tablicy o 2 raza wiekszej,
    jesli wspolczynik mniej od 0.125 to przehaszowujemy do tablicy o 2 raza mniejszej
    tutaj uzyto inne metoda do wstawienia elementow, dlatego ze, przy uzyciu zwyklej metody my uzywamy wskaznik na metodu haszowania (liniowa/kwadratowa/podwojne)
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
            if(table[i].key == "busy")
            {
                SetColor(0,4);
                cout<<table[i].key<<"[ "<<table[i].value.key<<" ]"<<endl;
            }
            else
            {
                SetColor(0,15);
                cout<<table[i].key<<"[ "<<table[i].value.key<<" ]"<<endl;
            }
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
            //cout<<"proba = "<<proba<<endl;
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
    unsigned long hash_number = hashModul(str, size_H) + (proba+hashModul(str,size_H - proba));
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
template <typename T>
int dlugProbkowania(HashTable<T> *ht)
{
    int i,c,m;
    m = 1;
    c = 1;
    for(int i = 0; i < ht->HASH_TABLE_SIZE; i++)
    {
        if(ht->table[i].key == "busy")
        {
            if(ht->table[i].key == ht->table[i+1].key)
            {
                c++;
                if(c>m) m=c;
            }
            else c=1;
        }
    }
    return m;
}
/// ///////////////////////////////////////////////////////////
int main()
{
    // Kod do testowania
    srand( time(0) );
    int dlugoscHashTab = 1000;
    int iloscElementow = 600;
    int iloscPowtorzen = 100;

    unsigned long ((*ptr_func_metod[3]))(string key, int proba, unsigned long size_H);
    string ptr_func_name[3];
    ptr_func_metod[0] = hashLine;
    ptr_func_name[0] = "METODA LINIOWA";
    ptr_func_metod[1] = hashQuadratic;
    ptr_func_name[1] = "METODA KWADRATOWA";
    ptr_func_metod[2] = hashDouble;
    ptr_func_name[2] = "METODA PODWOJNA";

    /*HashTable<Person> newTable(dlugoscHashTab);

    for(int i = 0; i < 20; i++)
    {
        Person *hl = new Person(randString(2,15), "test", 10);
        newTable.insert(hl, hashLine);
    }
    newTable.print();*/
    for(int f = 0; f < 3; f++)
    {
        cout<<endl<<"\t ["<<ptr_func_name[f]<<"]"<<endl<<endl;
        int sred = 0;
        int max = 0;
        int min = 0;
        for(int i = 0; i < iloscPowtorzen; i++)
        {
            HashTable<Person> newTable(dlugoscHashTab);

            for(int j = 0; j < iloscElementow; j++)
            {
                Person *hl = new Person(randString(2,15), "test", 10);
                newTable.insert(hl, ptr_func_metod[f]);
            }
            sred += dlugProbkowania(&newTable);
        }
        cout<<"srednia dlugos probkowania -> ["<<(sred/iloscPowtorzen)<<"]"<<endl;
        sred = 0;
    }
    return 0;
}














