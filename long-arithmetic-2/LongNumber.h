#ifndef LN_H
#define LN_H
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class LongNumber
{
private:
    struct Node
    {
        int data;
        Node * next;
        Node * previous;
        Node(int d, Node * n = nullptr, Node * p = nullptr)
        {
            data = d;
            next = n;
            previous = p;
        }
    };

    int sign = 1;
    int digit = 10;
    int size = 0;
    Node * head = nullptr;
    Node * tail = nullptr;


    void addElement(int d);
    void addFront(int d);
    void addFront2(int d);
    void deletAll();
    friend bool helpOperator(LongNumber & left, LongNumber & right);
    friend void helpOdejmovanie(LongNumber & left, LongNumber & right, LongNumber & newNumber);

public:
    LongNumber(string number, int dig);
    LongNumber() = default;
    LongNumber(const LongNumber & ln);
    ~LongNumber();
    void printNumber();

    LongNumber & operator = (const LongNumber & ln);
    bool operator < ( LongNumber & ln);
    bool operator > ( LongNumber & ln);
    bool operator == ( LongNumber & ln);

    LongNumber operator + (LongNumber & ln);
    LongNumber operator - (LongNumber & ln);

    friend ostream & operator<<(ostream& os, LongNumber & ln);


};


#endif // LN_H
